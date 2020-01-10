/****************************************************************
FILE:complex.h
AUTHOR: Eduardo Leanos

PURPOSE:The declaration file header for header.cpp
*****************************************************************/

#ifndef COMPLEX_H

#define COMPLEX_H


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <istream>
#include <ostream>

using namespace std;

class Complex{ //The complex class
	private:
		double realPart, //Real part of the number
		       imaginaryPart; //The imaginary part of the number, i
	public:
		Complex(double=0,double=0); //Constructor that initilizes parametters not passed in as 0
		void setComplex(double,double); //Set the complex number
		void getComplex(double&, double&)const; //Get the complex number
		void setRealPart(double);
		double getRealPart()const;
		void setImaginaryPart(double);
		double getImaginaryPart()const;
		Complex operator+(const Complex&)const; //+ operator method for complex numbers
		Complex operator*(const Complex&)const; //* operator method for complex numbers
		bool operator==(const Complex&)const; //== operator for complex 
		friend ostream &operator<<(ostream&, const Complex&);  //friend function for << operator in ostream class
		friend istream &operator>>(istream&, Complex&); //friend function for >> operator in istream class
};

#endif
