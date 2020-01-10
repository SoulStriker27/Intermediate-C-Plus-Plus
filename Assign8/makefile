#
# PROGRAM:    Assign8
# PROGRAMMER: Eduardo Leanos
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o maze.o
	g++ $(CCFLAGS) -o assign8 assign8.o maze.o

# Rules to compile source code files to object code
assign8.o: assign8.cpp maze.h
	g++ $(CCFLAGS) -c assign8.cpp

maze.o: maze.cpp maze.h
	g++ $(CCFLAGS) -c maze.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8
