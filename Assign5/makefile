#Eduardo Leanos
#Makefile
assign5: assign5.o NIUString.o
	g++ -Wall -std=c++11 -o assign5 assign5.o NIUString.o

assign5.o: assign5.cpp NIUString.h
	g++ -Wall -std=c++11  -c assign5.cpp

NIUString.o: NIUString.cpp NIUString.h
	g++ -Wall -std=c++11 -c NIUString.cpp

clean:
	-rm *.o assign5
