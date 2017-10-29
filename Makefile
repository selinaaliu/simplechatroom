TARGETS = chatroomserver

all: $(TARGETS)

%.o: %.cc
	g++ $^ --std=c++11 -g -c -o $@ 

chatroomserver: text.pb.o chatroomserver.o
	g++ $^ -o $@ -lprotobuf -lpthread

clean::
	rm -fv $(TARGETS) *~ *.o
