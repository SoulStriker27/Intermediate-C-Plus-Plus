// Header: Main.cpp
// Programmer: Eduardo Leanos
//
// Purpose: This assignment reviews object-oriented programming
// concepts such as classes, methods, constructors, accessor
// methods, and access modifiers. It makes use of an array of
// objects as a class data member, and introduces the concept
//  of object serialization or "binary I/O".

#include "AccountDB.h"
#include "BankAccount.h"

int main(){
   AccountDB bankAccounts("accounts"); //Make overloaded AccountDB object with "accounts" file
   bankAccounts.print(); //Print Account object
   bankAccounts.processTransactions("transactions.txt"); //Process AccountDb object with new information from "transactions.txt"
   bankAccounts.print(); //Print AccountDB object with new data
};

