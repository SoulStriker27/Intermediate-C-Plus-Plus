#ifndef NIUSTRING_H
#define NIUSTRING_H

/****************************************************************
FILE:NIUString.h
AUTHOR: Eduardo Leanos

PURPOSE:The header file for NIUString.cpp
*****************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <ostream>
#include <istream>
#include <algorithm>

using namespace std; //Used to not call std:: all the time

class NIUString{//The NIUString class
	private:
		char* strArray; //The char pointer for the array
		size_t cap; //The capacity for the array
		size_t strSize; //THe size of the array
	public:
		NIUString(); //Constructor
		NIUString(const char*); //Constructor with string parameter
		NIUString(const NIUString&);//Constructor with NIUString parameter
		~NIUString(); //Deconstructor
		NIUString& operator=(const NIUString&);  //Setting NUIString object with NIUString object
		NIUString& operator=(const char*); //Setting NIUString object with string
		size_t capacity() const; //Get method for capacity
		size_t size() const; //Get method for size
		bool empty() const; //Get method for empty
		void clear(); //Reset object
		void reserve(size_t);//Reserve memory for unsigned int
		bool operator==(const NIUString&) const;
		bool operator==(const char*) const;
		const char& operator[](size_t) const;
		char& operator[](size_t);
		friend ostream& operator<<(ostream&, const NIUString&); //Friend ostream operand
		friend bool operator==(const char*, const NIUString&); //Friend operator==

		//Extra credit:
		NIUString(NIUString&&);
		NIUString& operator=(NIUString&&);

};

#endif 
