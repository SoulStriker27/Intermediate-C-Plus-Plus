#include "AccountDB.h"  //Include header
#include <cstring>
//*****************************************************************/
// FILE:      BankAccount.cpp
// AUTHOR:    Eduardo Leanos
// PURPOSE:   Contains the Methods for the AccountDB class.
//*****************************************************************/

/***************************************************************
Method: AccountDB::AccountDB()
Use: Constructor
Parameters: None
Returns: Nothing
Notes: Set name of bank name and valid to 0
***************************************************************/

AccountDB::AccountDB(){ //Initilize default constructor with a bank name and intialize valid
   strcpy(bankName,"First National Bank");
   valid = 0;
};

/***************************************************************
Method: AccountDB::AccountDB()
Use: Overload constructor
Parameters: const char* filename
Returns: Nothing
Notes:Passed int the file name into this
***************************************************************/

AccountDB::AccountDB(const char* filename){ //Initilize overload constructor with text file
   ifstream inFile(filename);  //Set inFile with text file
   if(!inFile){  //Check whether it file opens
       cout << "Error Opening file";
       exit(1);  //Close program if it doesn't
   };
   inFile.read((char*) this, sizeof(AccountDB)); //Use read method to put inFile contents into this
   inFile.close();                               //While using the size of AccountDB, then close file
   AccountDB::sortAccounts(); //Call sort accounts to sort BankAccount object arrays
};

/***************************************************************
Method:
Use:
Parameters:
Returns:
Notes:
***************************************************************/

void AccountDB::print() const{  //Print organized account arrrays
   cout << endl << "Account listings for " << this->bankName << endl << endl;
   for(int i = 0; i < valid; i++){
      bankAccounts[i].print();
      cout << endl;
   }
};

/***************************************************************
Method: AccountDB::sortAccount()
Use: sort the BankAccount objects
Parameters: None
Returns: Nothing
Notes: Temp BankAccount object was made: BankAccount bucket
***************************************************************/

void AccountDB::sortAccounts(){  //Sort the BankAccount objects by account numbers
   {
   int i, j;
   BankAccount bucket;  //Create  temp BankAccount object to transfer information
   for(i = 1; i < valid; i++){
      bucket = bankAccounts[i]; //Set temp with file we are cheking
      for(j = i; (j > 0) && (strcmp(bankAccounts[j-1].getAccNum(), bucket.getAccNum()) > 0); j--) //Compare account strings
         bankAccounts[j] = bankAccounts[j-1]; //Organize account arrays until it is lower than bankAccounts[i]
      bankAccounts[j] = bucket;
      }
   }
};

/***************************************************************
Method: AccountDB::seachForAccount()
Use: Make sure the account number is valid
Parameters: const char* searchNumber 
Returns: -1 if account is not found
Notes:
***************************************************************/

int AccountDB::searchForAccount(const char* searchNumber) const{ //Search for an account number
   int low = 0;
   int high = valid - 1;
   int mid;
   while (low <= high){  //Use binary sort
      mid = (low + high) / 2;
      if (strcmp(searchNumber, AccountDB::bankAccounts[mid].getAccNum()) == 0)
         return mid;
      if (strcmp(searchNumber, bankAccounts[mid].getAccNum()) < 0)
         high = mid - 1;
      else
         low = mid + 1;
      }
   return -1;
};

/***************************************************************
Method: Account::processTransactions()
Use: Process either the deposit of withdrawal of the accounts
the print the information chart
Parameters: const char* fileName
Returns: nothing
Notes: This method is extra long so I tried to seperate the cout
portion from the logic part
***************************************************************/

void AccountDB::processTransactions(const char* fileName){ // Process the Transaction
   char transactionDate[5]; //Variables
   char accountNumber[11];
   char transactionType;
   double transactionAmount;
   bool withdrawalAccepted;
   ifstream inFile(fileName);  //Open file
   if(!inFile){  //Test file
       cout << "Error Opening file";
       exit(1);  //Close program if opening file fails
   };

   cout << fixed << left <<  "Transaction Report:" << endl << endl;
   cout <<  setw(8) << "Date" << setw(16) << "Account" << setw(8) <<           //Header for bank account listings
   "Type" << setw(14) << "Amount" << setw(18) <<  "New Balance" << endl << endl;

   inFile >> transactionDate;  //Read files into transaction date
   while (inFile){ //While still reading files
      inFile >> accountNumber;  //Read files into: account number
      inFile >> transactionType;               //  transaction type
      inFile >> transactionAmount;             //  transaction amount

      cout <<  setw(8)  << transactionDate << setw(16) << accountNumber << setw(8) <<  // Cout to display variables
      transactionType << setw(10) << setprecision(2) << fixed << setw(14) << transactionAmount;

      int index = AccountDB::searchForAccount(accountNumber); //Call searchForAccount
      if (index == -1)
         cout << "**account not found**" << endl; //If search fails
      else{
         if (transactionType == 'D'){  //Check if it a deposit or a withdrawal
	    bankAccounts[index].processDeposit(transactionAmount);  //call processDeposit with transactionAmount as parameter
	    cout <<  bankAccounts[index].getBal() << endl;   //Display new balance
         }
         else{
	    withdrawalAccepted = bankAccounts[index].processWithdrawal(transactionAmount); //Call processWithdrawal and return true or false
            if(withdrawalAccepted == true)  
		cout << setw(12) << bankAccounts[index].getBal() << endl;  //If true display new account balance
            else
                cout << "**Insuficient funds**" << endl; //Display if funds do not support that type of withdrawal
            }
         }
         inFile >> transactionDate;
      }

   inFile.close(); //Close file

};


