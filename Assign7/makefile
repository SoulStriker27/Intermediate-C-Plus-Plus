#Edaurdo Leanos
#Makefile
CFLAGS=-Wall -std=c++11

assign7: assign7.o
	g++ $(CCFLAGS) -o assign7 assign7.o

assign7.o: assign7.cpp Stack.h
	g++ $(CCFLAGS) -c assign7.cpp
clean:
	-rm *.o assign7
