#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <queue>
#include <tuple>
#include <map> 
#include "text.pb.h"

using namespace std;

static inline std::string &rtrim(std::string &s) {
    s.erase(find_if(s.rbegin(), s.rend(),
                std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

struct Address {
    uint32_t addr;
    uint16_t port;
};

bool operator < (const Address &a, const Address &b) {
    return tie(a.addr, a.port) < tie(b.addr, b.port);
}
bool operator == (const Address &a, const Address &b) {
    return a.addr == b.addr && a.port == b.port;
}

// data of cluster of servers
struct Cluster {
    set<Address> peers;
    int serverId;
    Address faddr;
    Address baddr;
};

struct User {
    string id;
    string nickname;
    int roomId;
    int counterByRoom[10];
};

// data of local clients
map<Address, User> clients;
map<int, vector<Address> > chatrooms;

bool operator < (const Text &a, const Text &b) {
    return a.msgid() > b.msgid();
}

struct FifoQueue {
    int lastMsgId;
    priority_queue<Text> queue; // FifoMsg with lowest id will be at the top
};

map<string, FifoQueue> fifoQueueMap;

int sockfd;
int debug_mode = 0;
int order_mode = 0;
Cluster cl;

void populateCluster(const char* filename, Cluster &cl);
void runServer();
void handleNewClient(Address &clientAddr, string msg);
void handleExistingClient(Address &clientAddr, string msg);
void handlePeerServer(Address &serverAddr, string msg);
void handleClientMsg(Address &clientAddr, string msg);
void forwardToServers(Text &text);
void localDeliver(Text text);
void fifoDeliver(Text &text);

void refreshQueue(FifoQueue &fq) {
    while (!fq.queue.empty()) {
        const Text &top = fq.queue.top();
        if (top.msgid() != fq.lastMsgId) break;
        fq.lastMsgId++;
        localDeliver(top);
        fq.queue.pop();
    }
}

void client_nick(Address client, string const &name);
void client_part(Address client);
void client_quit(Address client);
void client_join(Address client, int newRoomId);

void throwSysError(const char* msg) { perror(msg); exit(1); }
void throwMyError(const char* msg) { fprintf(stderr, "%s\n", msg); exit(1); }

// server sends response to client
void sendResponse(struct Address client, const char *msg, int val) {
    struct sockaddr_in addr; bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = client.addr;
    addr.sin_port = client.port;
    char buf[strlen(msg) + 3];
    sprintf(buf, "%s%d", msg, val);
    int status = sendto(sockfd, buf, strlen(buf), 0, 
                    (struct sockaddr*) &addr, sizeof(addr));
    if (status < 0) throwSysError("Error sending response to client");
}

void sendResponse(struct Address client, const char *msg, const char *val) {
    struct sockaddr_in addr; bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = client.addr;
    addr.sin_port = client.port;
    char buf[strlen(msg) + strlen(val)];
    sprintf(buf, "%s %s", msg, val);
    int status = sendto(sockfd, buf, strlen(buf), 0, 
                    (struct sockaddr*) &addr, sizeof(addr));
    if (status < 0) throwSysError("Error sending response to client");
}

void sendResponse(struct Address client, const char *msg) {
    struct sockaddr_in addr; bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = client.addr;
    addr.sin_port = client.port;
    int status = sendto(sockfd, msg, strlen(msg), 0, 
                    (struct sockaddr*) &addr, sizeof(addr));
    if (status < 0) throwSysError("Error sending response to client");
}

string getFormattedTime() {
    char buffer1[80], buffer2[80];
    struct timeval rawtime;
    gettimeofday(&rawtime, NULL);
    struct tm *timeinfo = localtime(&rawtime.tv_sec);
    strftime(buffer1,80,"%R:%S",timeinfo);
    snprintf(buffer2,80, "%s.%06d", buffer1, rawtime.tv_usec);
    string out(buffer2);
    return out;
}

void debug_msg(const char* msg) {
    string time = getFormattedTime();
    printf("%s S%02d %s\n", time.c_str(), cl.serverId, msg);
}

void debug_msg(const char* msg, int val) {
    string time = getFormattedTime();
    printf("%s S%02d %s %d\n", time.c_str(), cl.serverId, msg, val);
}

void debug_msg(const char* msg, const char *val) {
    string time = getFormattedTime();
    printf("%s S%02d %s %s\n", time.c_str(), cl.serverId, msg, val);
}

int main(int argc, char *argv[]) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    if (argc < 2) {
        fprintf(stderr, "*** Author: Selina Liu (liu15)\n");
        exit(1);
    }
    int c;
    while ((c = getopt(argc, argv, "o:v")) != -1) {
        switch (c) {
            case 'o':
                if (strcmp(optarg,"unordered") == 0) {
                    order_mode = 0;
                    if(debug_mode) debug_msg("Mode is Unordered");
                } else if (strcmp(optarg,"fifo") == 0) {
                    order_mode = 1;
                    if(debug_mode) debug_msg("Mode is Fifo Ordering");
                } else if (strcmp(optarg,"total") == 0) {
                    order_mode = 2;
                    if(debug_mode) debug_msg("Mode is Total Ordering");
                } else {
                    throwMyError("Not a valid option");
                }
                break;
            case 'v':
                debug_mode = 1; // turn on debug mode 
                break;
            default:
                throwMyError("Not a valid option");
        }
    }

    if (argv[optind] == NULL) throwMyError("No file and server index specified");
    if (argv[optind+1] == NULL) throwMyError("No server index specified");

    const char *filename = argv[optind];
    cl.serverId = atoi(argv[optind+1]) - 1;
    populateCluster(filename, cl);
    runServer();
    return 0;
}

void populateCluster(const char* filename, Cluster &cl) {
    ifstream infile(filename);
    string line;
    size_t com, col;
    string::size_type sz;
    int counter = 0;
    while (getline(infile, line)) {
        struct Address curr;
        com= line.find(",");
        col= line.find(":");
        curr.addr = inet_addr(line.substr(0,col).c_str());
        curr.port = htons(stoi(line.substr(col+1,com-col-1), &sz));
        if (counter != cl.serverId) cl.peers.insert(curr);
        else {
            cl.faddr = curr;
            if (com != string::npos) {
                col= line.find(":", col+1);
                cl.baddr.addr = inet_addr(line.substr(com+1,col-com-1).c_str());
                cl.baddr.port = htons(stoi(line.substr(col+1), &sz));
            }
        }
        counter++;
    }
}

void runServer() {
    int status;
    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = cl.baddr.port;
    servaddr.sin_addr.s_addr = cl.baddr.addr;
    status = ::bind(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
    if (status < 0) { throwSysError("Socket did not bind"); } 

    char buffer[120];
    bzero(buffer, sizeof(buffer));

    while (true) {
        struct sockaddr_in fromAddr;
        socklen_t fromSize = sizeof(fromAddr);
        bzero(&fromAddr, sizeof(fromAddr));

        int rlen = recvfrom(sockfd, buffer, sizeof(buffer)-1, 0,
                (struct sockaddr*) &fromAddr, &fromSize);

        buffer[rlen] = 0; // end the msg
        string data(buffer);
        struct Address fromAddress = {fromAddr.sin_addr.s_addr, fromAddr.sin_port};
        
        // from peer server
        if (cl.peers.find(fromAddress) != cl.peers.end()) { 
            handlePeerServer(fromAddress, data);
        } 
        // from existing client
        else if (clients.find(fromAddress) != clients.end()) { 
            handleExistingClient(fromAddress, data);
        } 
        // from new client
        else { 
            handleNewClient(fromAddress, data);
        }
        bzero(buffer, sizeof(buffer));
    }
}

void handlePeerServer(Address &serverAddr, string msg) {
    Text text;
    text.ParseFromString(msg);
}

void handleExistingClient(Address &clientAddr, string msg) { 
    rtrim(msg);
    int currRoomId = clients[clientAddr].roomId;
    if (msg == "/join" || msg == "/nick") {
        sendResponse(clientAddr, "-ERR You need an argument");

    } else if (msg.substr(0,6) == "/join ") {
        int newroom = stoi(msg.substr(6));
        client_join(clientAddr, newroom);
    } else if (msg.substr(0,5) == "/part") {
        client_part(clientAddr);
    } else if (msg.substr(0,6) == "/nick ") {
        string name = msg.substr(6);
        client_nick(clientAddr, name);
    } else if (msg.substr(0,5) == "/quit") {
        client_quit(clientAddr);
    } 
    else { // client sends a message to the group
        handleClientMsg(clientAddr, msg);
    }
}

void handleNewClient(Address &clientAddr, string msg) {
    if (msg.substr(0,6) != "/join ") {
        sendResponse(clientAddr, "-ERR please join a room first");
        return;
    }

    int roomId = stoi(msg.substr(6));
    in_addr wrapper; wrapper.s_addr = clientAddr.addr;
    string addrId = inet_ntoa(wrapper) + string(":") 
        + to_string(ntohs(clientAddr.port));

    // add client to list of clients
    User newUser = {addrId, addrId, roomId, 0};
    clients[clientAddr] = newUser; 
    chatrooms[roomId].push_back(clientAddr);

    sendResponse(clientAddr, "+OK You are now in chat room #", roomId);
    if (debug_mode) debug_msg("New client joined room #", roomId);
}

void handleClientMsg(Address &clientAddr, string msg) {
    User &client = clients[clientAddr];
    Text text;
    text.set_chatroomid(client.roomId);
    text.set_nickname(client.nickname);
    text.set_content(msg);
    text.set_msgid(++(client.counterByRoom[client.roomId-1]));
    // local deliver
    localDeliver(text);
    // forward to servers
    forwardToServers(text);
}

void localDeliver(Text text) {
    vector<Address> &roomGuests = chatrooms[text.chatroomid()];    
    string msg = text.content();
    int status;
    for (int i = 0; i < roomGuests.size(); i++) {
        struct sockaddr_in curr;
        bzero(&curr, sizeof(curr));
        curr.sin_family = AF_INET;
        curr.sin_port = roomGuests[i].port;
        curr.sin_addr.s_addr = roomGuests[i].addr;
        status = sendto(sockfd, msg.c_str(), msg.size(), 0,
                    (struct sockaddr*) &curr, sizeof(curr));
        if (status < 0 && debug_mode) {
            debug_msg("Error delivering packet to clients");
        }
    }
}

void forwardToServers(Text &text) {
    string payload;
    text.SerializeToString(&payload);
    int status;
    for (auto peer : cl.peers) {
        struct sockaddr_in addr;
        bzero(&addr, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = peer.port;
        addr.sin_addr.s_addr = peer.addr;
        status = sendto(sockfd, payload.c_str(), payload.size(), 0, 
                (struct sockaddr*) &addr, sizeof(addr));
        if (status < 0 && debug_mode) {
            debug_msg("Error forwarding packet to other servers");
        }
    }
}

void fifoDeliver(Text &text) {
    string queueId = text.nickname() + to_string(text.chatroomid());
    FifoQueue &fq = fifoQueueMap[queueId];
    int prev = fq.lastMsgId;
    if (text.msgid() == (prev+1)) {
        localDeliver(text);
        fq.lastMsgId++;
        if (debug_mode) debug_msg("Received and delivered MSG #", text.msgid());
        // method to clear queue as long as top msg has same id as lastMsgId + 1
        refreshQueue(fq);
    } else if (text.msgid() > (prev+1)) { 
        fq.queue.push(text);
        if (debug_mode) debug_msg("Pushed to queue MSG #", text.msgid());
    } else {
        if (debug_mode) debug_msg("MSG received has been delivered");
    }
}


// HANDLERS FOR COMMANDS FROM CLIENTS
void client_quit(Address client) {
    int currRoomId = clients[client].roomId;
    string clientId = clients[client].id;
    clients.erase(client);
    if (currRoomId > 0) {
        vector<Address> &room = chatrooms[currRoomId];
        vector<Address>::iterator it = find(room.begin(), room.end(), client);
        room.erase(it);
    }
    if (debug_mode) debug_msg("Client quitted", clientId.c_str());
} 

void client_part(Address client) {
    int currRoomId = clients[client].roomId; 
    if (currRoomId == 0) {
        sendResponse(client, "-ERR you are not in a room yet");
        return;
    }
    vector<Address> &room = chatrooms[currRoomId];
    vector<Address>::iterator it = find(room.begin(), room.end(), client);
    room.erase(it);
    clients[client].roomId = 0;
    sendResponse(client, "+OK You have left chat room #", currRoomId);
    if (debug_mode) debug_msg("Client left chat room #", currRoomId);
}

void client_nick(Address client, string const &name) {
    clients[client].nickname = name;
    sendResponse(client, "+OK Your new nickname is", name.c_str());
    if (debug_mode) debug_msg("Client changed nickname to", name.c_str());
}

void client_join(Address client, int newRoomId) {
    int currRoomId = clients[client].roomId; 
    if (currRoomId != 0) {
        sendResponse(client, "-ERR you are already in room #", currRoomId);
        return;
    }
    clients[client].roomId = newRoomId;
    chatrooms[newRoomId].push_back(client);
    sendResponse(client, "+OK You are now in chat room #", newRoomId);
    if (debug_mode) debug_msg("Client joined chat room #", newRoomId);
}

