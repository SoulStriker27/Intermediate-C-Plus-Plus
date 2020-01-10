#ifndef ACCOUNTDB_H

#define ACCOUNTDB_H

#include "BankAccount.h"
#include <fstream>

//*****************************************************************
// FILE:      AccountDB.h
// AUTHOR:    Eduardo Leanos
// PURPOSE:   The header for the database for bank account objects.
//*****************************************************************

class AccountDB{  //AccountDB class
   private:
      char bankName[31];    //Char array of 31 elements
      BankAccount bankAccounts[20];   //Intialize an array of BankAccount objects
      int valid;  //Variable to determine the amount of valid objects
   public:
      AccountDB();  //Constructor
      AccountDB(const char* filename); //Overload constructor using a file
      void print() const;
      void sortAccounts();
      int searchForAccount(const char*) const;
      void processTransactions(const char*);
};

#endif // ACCOUNTDB_H
