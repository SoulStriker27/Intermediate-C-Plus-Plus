/****************************************************************
FILE:complex.cpp
AUTHOR: Eduardo Leanos

PURPOSE:The definitions for the complex.h, Complex class.
*****************************************************************/

#include "complex.h"
#include <iostream>
#include <istream>

/***************************************************************
Function:Complex
Parameters:2 doubles, if not intitilized set the values to 0
Returns: Nothing
Notes: The constructor
***************************************************************/ 

Complex::Complex(double real, double imaginarynum){
	realPart = real; //Constructor to set real and imaginary parts
	imaginaryPart = imaginarynum;
}

/***************************************************************
Function:SetComplex
Parameters:2 doubles
Returns:Nothing
Notes:Sets object with data
***************************************************************/ 

void Complex::setComplex(double real, double imaginarynum){
	realPart = real; //Just to set Complex number as part of a call aside from constructor
	imaginaryPart = imaginarynum;
}

/***************************************************************
Function:getComplex
Parameters:2 refrences to the doubles passed in
Returns:nothing
Notes:Changes the values past in
***************************************************************/ 

void Complex::getComplex(double& real, double& imaginarynum)const{
	real = realPart; //To get Complex numbers
	imaginarynum = imaginaryPart;
}

/***************************************************************
Function:setRealPart
Parameters:A double
Returns:Nothing
Notes:Set the real part
***************************************************************/ 

void Complex::setRealPart(double real){
	realPart = real; //Set the real part of the complex number
}

/***************************************************************
Function:getRealPart
Parameters:Nothing
Returns:double, the real part of the complex number
Notes:
***************************i************************************/ 

double Complex::getRealPart()const{
	return realPart; //Get the real part of the complex number
}

/***************************************************************
Function:setImaginaryPart
Parameters:a double
Returns:Nothing
Notes:Sets the imaginaryPart a value
***************************************************************/ 

void Complex::setImaginaryPart(double imaginarynum){
	imaginaryPart = imaginarynum; //Set imaginary part of complex number
}

/***************************************************************
Function:getImaginaryPart
Parameters:None
Returns:double
Notes:Get the imaginary part of the complex number
***************************************************************/ 

double Complex::getImaginaryPart()const{
	return imaginaryPart; //Get imaginary part of complex number
}

/***************************************************************
Function:Complex operator+
Parameters:The right Complex object operand
Returns:A Complex object
Notes:Add up the 2 real parts and 2 imaginary parts
***************************************************************/ 

Complex Complex::operator+(const Complex& rhs)const{
	Complex result = *this; //Call the Complex object calling this method
	result.realPart = (result.realPart + rhs.realPart); //Add 2 Complex number real part
	result.imaginaryPart = (result.imaginaryPart + rhs.imaginaryPart); //Ass 2 Complex numbers imaginaryPart
	return result; //Return updated Complex object
}

/***************************************************************
Function:Complex operator*
Parameters:A right Complex object operand
Returns: A Complex object
Notes:Using overloading arithmetic operations
***************************************************************/ 

Complex Complex::operator*(const Complex& rhs)const{
	Complex result = *this; //Call the Complex number callind this method
	Complex result2 = *this; //Call a second time to use the same numbers in a second equation
	result.realPart = ((result.realPart * rhs.realPart) - (result.imaginaryPart * rhs.imaginaryPart)); //(ac)-i(bd)
	result.imaginaryPart = ((result2.realPart * rhs.imaginaryPart) + (rhs.realPart * result2.imaginaryPart));//(ad)+(cb)
	return result;//Return updated object
}
					
/***************************************************************
Function:bool operator==
Parameters:A Comlex refrence to right operand
Returns:a bool, if it equals true
Notes:
***************************************************************/ 

bool Complex::operator==(const Complex& rhs)const{//==operator(Complex object compare)
	Complex result = *this;
	if(result.realPart == rhs.realPart && result.imaginaryPart == rhs.imaginaryPart) //Check equality with 2 Complex objects
		return true; //If equal                                                    Cheacking realParts together and imaginaryParts together
	else
		return false; //If false
}

/***************************************************************
Function:ostream& operator
Parameters:ostream refrence and a Complex object reference
Returns:The left hand operand, lhs
Notes:Basically does the cout for objects
***************************************************************/ 

ostream& operator<<(ostream& lhs, const Complex& rhs){//<<operator (cout)
	lhs << '(' << rhs.realPart << ", " << rhs.imaginaryPart << ')'; //'lhs' is now 'cout <<' to objects
	return lhs; //Make sure the cout/lhs works right, return it
}

/***************************************************************
Function:istream& operator>>
Parameters:istream refrence and Complex object refrence
Returns:reference to the istream object
Notes:Does the cin for objects
***************************************************************/ 

istream& operator>>(istream& lhs, Complex& rhs){//>>operator (cin)
	char ch; //Temp unused character
	lhs >> ch; //Put in first unused char character
       	lhs >> rhs.realPart; //Put in realPart
	lhs >> ch; //unused
        lhs >> rhs.imaginaryPart; //Put in imaginaryPart
        lhs >> ch; //unused
	return lhs; //Make sure the cin/lhs works right, return it
}

