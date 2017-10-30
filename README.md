# Simple Chat Room
Simple chat room with server-client implementation using Google Protobuf.

Message delivery follows fifo ordering. 

## Config files

`config1.txt` is a sample servers config file listing the binding addresses of all servers in the cluster.

`config2.txt` is a sample servers config file listing <forwarding address, binding address> for each server in the cluster.

## To launch the chat room:

1. Compile source code: `make clean && make`

2. To start a server: `./chatroomserver -v -o fifo <servers config file> <server id>`

e.g. `./chatroomserver -v -o fifo config.txt 1`

3. To attach a chat client to a server: `./chatroomclient <server address:server port>` 

e.g. `./chatroomclient <127.0.0.1:5000>`
