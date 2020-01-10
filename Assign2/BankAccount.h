#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

/*****************************************************************
FILE:      BankAccount.h
AUTHOR:    Eduardo Leanos
PURPOSE:   Contains the declaration for the BankAccount class.
*****************************************************************/

class BankAccount{ // BankAccount class
   private:
      char accNum[11];   //Account number
      char custName[21];   //Name of customer
      double accBal;   //Balance of account
   public:
      BankAccount();    //Constructor
      BankAccount(const char*, const char*, double); //Overload constructor
      const char* getAccNum() const;  //Retrieve account number
      const char* getName() const;   //Retrieve account name
      double getBal();   //Retrieve account balance
      void processDeposit(double amount);
      bool processWithdrawal(double amount);
      void print() const; //Print private variables
};

#endif
