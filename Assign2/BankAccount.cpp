#include "BankAccount.h"

/*****************************************************************
FILE:      BankAccount.cpp
AUTHOR:    Eduardo Leanos
PURPOSE:   Contains the methods for the BankAccount class.
*****************************************************************/

/***************************************************************
Method: BankAccount::BankAccount()
Use: Constructor
Parameters: None
Returns: Nothing
Notes: Initialize variables to zero
***************************************************************/ 

BankAccount::BankAccount(){  //Initialize variables to zero
   accNum[0] = {};
   custName[0] = {};
   accBal = 0;
};

/***************************************************************
Method: BankAccount::BankAccount(const char*, const char*, double)
Use: Overload constructor, set variables to a to parameter specific
data 
Parameters: const char*, const char*, double
Returns:Nothing
Notes:
***************************************************************/


BankAccount::BankAccount(const char* newAccNum, const char* newName, double newBal){ //Initialize variables to
   strcpy(accNum, newAccNum);                                                        //information passed in
   strcpy(custName, newName);
   accBal = newBal;
};

/***************************************************************
Method: BankAccount::GetAccNum()
Use: Get account number
Parameters: None
Returns: Account number
Notes:
***************************************************************/

const char* BankAccount::getAccNum() const {
   return accNum;
};

/***************************************************************
Method: BankAccount::getName()
Use: Get account name
Parameters: None
Returns: Customer Name
Notes:
***************************************************************/

const char* BankAccount::getName() const {
   return custName;
};

/***************************************************************
Method: BankAccount::getBal()
Use: Get account balance
Parameters: None
Returns: Account balance
Notes:
***************************************************************/

double BankAccount::getBal(){
   return accBal;
};

/***************************************************************
Method: BankAccount::processDeposit()
Use: Add deposit to current account balance
Parameters: double, the amount being deposited
Returns: nothing
Notes:
***************************************************************/

void BankAccount::processDeposit(double amount){ //Add amount passed in to the account balance
   accBal += amount;
};

/***************************************************************
Method: BankaAccount::processWithdrawal()
Use: Get money from account balance
Parameters: double, the amount to be withdrawn
Returns: false if amount > balance, true otherwise
Notes: Subtracts from balance if true
***************************************************************/

bool BankAccount::processWithdrawal(double amount){ //Process withdrawal and return bool data type depending on result
   if (amount > accBal)
      return false;
   else{
      accBal -= amount;
      return true;
   };
};

/***************************************************************
Method: BankAccount::print()
Use: Print bank account object
Parameters: None
Returns: Nothing
Notes:
***************************************************************/

void BankAccount::print() const{
   std::cout << "Account Number: " << accNum << std::endl;
   std::cout << "Name: " << custName << std::endl;
   std::cout << setprecision(2) << fixed << "Balance: $" << accBal << std::endl; 
};
