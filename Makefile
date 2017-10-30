TARGETS = chatroomserver chatroomclient

all: $(TARGETS)

%.o: %.cc
	g++ $^ --std=c++11 -g -c -o $@ 

chatroomserver: text.pb.o chatroomserver.o
	g++ $^ -o $@ -lprotobuf -lpthread

chatroomclient: chatroomclient.o
	g++ $^ -o $@

clean::
	rm -fv $(TARGETS) *~ *.o
