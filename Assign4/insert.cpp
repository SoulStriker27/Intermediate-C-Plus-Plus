
#ifndef COMPLEX_H

#define COMPLEX_H


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Complex{
	private:
		double realPart,
		       imaginaryPart;
	public:
		Complex(double=0,double=0);
		void setComplex(double,double);
		void getComplex(double&. double&);
		void setRealPart(double);
		double getRealPart();
		void setImaginaryPart(double);
		double getImaginaryPart();
		Complex operator+(const Complex&);
		Complex operator*(const Complex&);
		bool operator==(const Complex&);
		ostream& operator<<(ostream&, Complex&);
		istream& operator>>(istream&, Complex&);
}

#endif
