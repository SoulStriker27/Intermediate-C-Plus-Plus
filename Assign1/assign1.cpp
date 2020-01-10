/***********************************************************

Progammer: Eduardo Leanos

Purpose: This assignment is an exercise in writing, compiling,
 and executing a C++ program on the departmental UNIX system.
 It also covers the manipulation of C strings.
************************************************************/ 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

//Struct for Word count

struct WordCount
   {
   char word[31];
   int count;
   };

//Prototypes

int countWords(const char*, WordCount[]);
void stripPunctuation(char*);
void stringToUpper(char*);
int searchForWord(const char*, const WordCount[], int);
void sortWords(WordCount[], int);
void printWords(const WordCount[], int);

//Main

int main ( int argc, char* argv[] )
{
   WordCount wordArray[200];   //Construct 200 objects
   int numWords = 0;
   if( argc == 1){  //Check wether a file was assigned to be opened with ./assign1
      cout << "Usage: assign1 [file-name]" << endl << endl;
      exit(1);
   }
   numWords = countWords(argv[1], wordArray);   //Store number of distinct words in numWords
   sortWords(wordArray, numWords);   //Call function sortWords to arrange words
   cout << endl << "Word Counts for input.txt" << endl << endl;
   printWords(wordArray, numWords);  //Print final viewing product
   return 0;
}

//Functions

/***************************************************************
Name:CountWords
Use:Count how many times a word was used and remove it multiple
Parameters:1)A C string that will not be changed by the function
 and that contains the name of an input file; 2) an array of WordCount objects.
Returns:The number of distinct words that the function stored in the array 
**************************************************************/

int countWords(const char* fileName, WordCount wordArray[]){
   int numWords = 0;
   char word [31];
   int position = 0;
   ifstream inFile(fileName);    //Open the file
   if(!inFile){    //Check wether opening the file works
      cout << "There was an error opening the file" << fileName << endl;
      exit(1);
   }
   while(inFile >> word){   //Put the file inputs into the struct
      stripPunctuation(word);
      if (strlen(word) != 0) { 
          stringToUpper(word);  //Call stringToUpper
          position = searchForWord(word, wordArray,numWords);
          if(position == -1){
             strcpy(wordArray[numWords].word, word);
             wordArray[numWords].count = 1;
             numWords++;
          }
          else {
             wordArray[position].count += 1;
          }
      }
   }
   inFile.close();
   return numWords;
}

/***************************************************************
Name:stripPunctuation
Use:This function should remove any punctuation characters at
 the beginning and end of the C string s.
Parameters:1) A C string that contains a word to be stripped of punctuation.
Returns:Nothing
**************************************************************/

void stripPunctuation (char*s){
   char temp[50] = {};
   int i;
   int m; 
      for(i = 0, m = 0; s[i]!= '\0'; i++){ //Loops throught word
         if (!ispunct(s[i])){              //to remove punctuation
	    temp[m] = s[i];  //Put only alnum in temp[m]
            m++;
         }
      }
   strcpy(s, temp);   //Put final no punctuation work back into s
}

/***************************************************************
Name:stringToUpper
Use:This function should loop through the characters of the C string s
 and convert them to uppercase using the C library function toupper().
Parameters:1) A C string that contains a word to be converted to uppercase.
Returns:Nothing
**************************************************************/

void stringToUpper(char* s) {
   for (int i = 0; s[i] != '\0'; i++) { //Make all lowercase to upper
       s[i] = toupper(s[i]);
   }
}

/***************************************************************
Name:searchForWord
Use:This function should use the linear search algorithm to search
 for the C string word in wordArray.
Parameters: 1) A C string that will not be changed by this function
 and that contains a word to search for; 2) an array of WordCount
 objects to search that will not be changed by this function; 3)
 the number of elements in the array filled with valid data.
Returns:If the search was successful, returns the index of the array element that
 contains the word that was searched for, or -1 if the search fails.
**************************************************************/


int searchForWord(const char* word, const WordCount wordArray[], int numWords){
   for(int i = 0; i < numWords;i++){
      if(strcmp(wordArray[i].word, word)== 0){
         return i;
      }
   }
   return -1;
}

/***************************************************************
Name:sortWords
Use:This function should sort the array of WordCount objects
 in ascending order by account number using the selection sort algorithm.
Parameters:1) An array of WordCount objects to sort; 2) the number of elements
 in the array filled with valid data.
Returns:Nothing
**************************************************************/

void sortWords (WordCount wordArray[], int numWords){
   int min;
   WordCount temp;
   for(int x = 0; x <(numWords - 1); x++){   //Go through all the words
      min=x;
      for(int y = x+1 ; y < numWords; y++){  //Sort using selection sort algorithm
         if(strcmp(wordArray[y].word, wordArray[min].word) < 0){
            min = y;
         }
      }
      temp = wordArray[min];
      wordArray[min] = wordArray[x];   //Put words in correct order by 
      wordArray[x] = temp;             //creating a temp and switching their positions
   }
}

/***************************************************************
Name:printWords
Use:This function should loop through the array and print each
 word and its corresponding count, neatly formatted into columns
 similar to the sample output. It should also print the number of
 words in the file (which is equal to the sum of the counts) and
 the number of distinct words (equal to numWords).
Parameters:1) An array of WordCount objects to print that will
 not be changed by this function; 2) the number of elements in
 the array filled with valid data.
Returns:Nothing
**************************************************************/

void printWords ( const WordCount wordArray[], int numWords){
   cout << "Sorted Words" << fixed << right << setw(9) << "Counts" << endl;
   for ( int i = 0; i < numWords; i++) {
       cout <<  fixed << left << setw(12) <<  wordArray[i].word <<
       setw(6) << right << wordArray[i].count << endl;
   }
}
//Make it look pretty!
