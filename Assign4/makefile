
# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign4: assign4.o complex.o
	g++ $(CCFLAGS) -o assign4 assign4.o complex.o

# Rules to compile source code files to object code
assign4.o: assign4.cpp complex.h
	g++ $(CCFLAGS) -c assign4.cpp

complex.o: complex.cpp complex.h
	g++ $(CCFLAGS) -c complex.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4
