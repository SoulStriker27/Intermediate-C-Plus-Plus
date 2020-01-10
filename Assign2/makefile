#
# PROGRAM:    assign2
# PROGRAMMER: Eduardo Leannos
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign2: assign2.o BankAccount.o AccountDB.o
	g++ $(CCFLAGS) -o assign2 assign2.o BankAccount.o AccountDB.o

# Rules to compile source code files to object code
assign2.o: assign2.cpp AccountDB.h
	g++ $(CCFLAGS) -c assign2.cpp

BankAccount.o: BankAccount.cpp BankAccount.h
	g++ $(CCFLAGS) -c BankAccount.cpp

AccountDB.o: AccountDB.cpp AccountDB.h
	g++ $(CCFLAGS) -c AccountDB.cpp

# The AccountDB class depends on the BankAccount class
AccountDB.h: BankAccount.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign2

