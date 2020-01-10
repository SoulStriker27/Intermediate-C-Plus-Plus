#
# PROGRAM:    Assign3
# PROGRAMMER: Eduardo Leanos
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign3: assign3.o maze.o
	g++ $(CCFLAGS) -o assign3 assign3.o maze.o

# Rules to compile source code files to object code
assign3.o: assign3.cpp maze.h
	g++ $(CCFLAGS) -c assign3.cpp

maze.o: maze.cpp maze.h
	g++ $(CCFLAGS) -c maze.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign3
