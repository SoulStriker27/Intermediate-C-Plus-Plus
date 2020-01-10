/****************************************************************
FILE: NIUString.cpp
AUTHOR: Eduardo Leanos

PURPOSE:This assignment introduces the consept of dynamci memory allocation, destructors, copy constructors, and overloading the assigment operator, and also provide some insight into how the c++ string class works.
*****************************************************************/

#include "NIUString.h" //Include the header
/***************************************************************
Function:NIUSTring::NIUString()
Parameter: Nothing
Returns: Nothing
Notes: The constructor 
 **************************************************************/
NIUString::NIUString(){//For constructor set all values to 0 or NULL
	strSize = 0;
	cap = 0;
	strArray = nullptr;//Set array to nullptr
}

/***************************************************************
Function:NIUString::NIUString()
Parameters:const char*
Returns:Nothing
Notes:Use a char* to create object
***************************************************************/ 

NIUString::NIUString(const char* other){ //Make obkect with char pointer
	strSize = strlen(other); //SEt object size tto pointer char* size
	cap = strSize; //Set the capacity of object to the size
	if(cap == 0) //If capacity is zero, set array to nullptr
		strArray = nullptr;

	else
		strArray = new char[cap]; //Else dynamically allocate object array to new address at capacity 

	for(size_t i=0; i<strSize; i++)//Put char* into object array
		 strArray[i]=other[i];
}
/***************************************************************
Function:NIUString::NIUString()
Parameters:NIUString&
Returns:Nothing
Notes:Make new object with NIUString object
***************************************************************/ 

NIUString::NIUString(const NIUString& other){//Use NIUString object to create a new object
	this->strSize = other.strSize; //Set new object size with old object size
	this->cap = other.cap; //Set new object capacity with old object capacity
	if(cap == 0) //If capacity 0 set new oject array to 0
		this->strArray = nullptr;

	else 
		this->strArray = new char[cap]; //Or dynamically allocate new address for new array
	if(other.strSize !=0){
		for(size_t i=0; i<strSize; i++){
			strArray[i] = other.strArray[i];//Copy old object to new object
		}
	}
	
}

/***************************************************************
Function:NIUString::-NIUString
Parameters:None
Returns:Nothing
Notes:Call clear method to reset object
***************************************************************/ 

NIUString::~NIUString(){
	clear();//Call method to reset object
}

/***************************************************************
Function:NIUString& NIUString::operator=()
Parameters:const NIUString&
Returns:NIUString
Notes:Return the object that called the method
***************************************************************/ 

NIUString& NIUString::operator=(const NIUString& other){//Set object with another object
	if(this->strArray == other.strArray) //See if address of objects are equal
      		return *this;
	delete[] this->strArray; //Delete array to create new one
	this->strSize = other.strSize;
	this->cap = other.cap;
	if(this->cap == 0)
		this->strArray = nullptr; //Same as before
	
	else
		this->strArray = new char[cap];
	
	for(size_t i=0; i<this->strSize; i++){//Copy old array to new array
		this->strArray[i] = other.strArray[i];
	}
	return *this; //Return object that called method
}

/***************************************************************
Function:NIUString NIUString::operator=()
Parameters:const char*
Returns:NIUString
Notes:Return the object that called the method
***************************************************************/ 

NIUString& NIUString::operator=(const char* other){//Set object with char*
	delete[] strArray;//Delete old array
	strSize = strlen(other);
	cap = strSize;
	if(cap== 0)
		strArray = nullptr;
	else
		strArray = new char[cap]; //Same as before
	
	for(size_t i=0; i<this->strSize; i++){//Copy string into new array
		strArray[i] = other[i];
	}
	return *this;
}

/***************************************************************
Function:size_t NIUString::capacity() const
Parameters:none
Returns:size_t
Notes:
***************************************************************/ 

size_t NIUString::capacity() const{ //Returns string capacity
	return cap;
}

/***************************************************************
Function:size_t NIUString::size() const
Parameters:none
Returns:size_t
Notes:
***************************************************************/ 

size_t NIUString::size() const{ //Returns string size
	return strSize;
}

/***************************************************************
Function:bool NIUString::empty() const
Parameters:none
Returns:bool
Notes:
***************************************************************/ 

bool  NIUString::empty() const{ //Check if there is anything in the array A.K.A size
	if(strSize == 0)
		return true;
	return false;
}

/***************************************************************
Function:bool NIUString::clear()
Parameters:none
Returns:void/nothing
Notes:Resets object
***************************************************************/ 

void NIUString::clear(){//Resets the object passed in
	strSize = 0;
	cap = 0;
	delete[] strArray;
	strArray = nullptr;
}

/***************************************************************
Function:void NIUString::reserve()
Parameters:size_t
Returns:nothing
Notes:Reserves space for array to use
***************************************************************/ 
									
void NIUString::reserve(size_t n){
	if( n<strSize || n==strSize)//Check if passed in value is valid for the size of object
		return; //Return if true
	
	cap = n;
	char* temp; //Create temp char*
	if(cap ==0)
		temp = nullptr;
	
	else{
		temp = new char[cap]; //Set char* temp to new place in dynamic allocation	
	}
	
	for(size_t i=0; i<strSize; i++){ //Copy strArray into temp
		temp[i]=strArray[i];
	}	
	delete[] strArray; //Delete string array
	strArray = temp; //Make new string array point to temp address
	
}	

/***************************************************************
Function:bool NIUString::operator==() const
Parameters:const NIUString&
Returns:bool
Notes:Compare object to object
***************************************************************/ 

bool NIUString::operator==(const NIUString& rhs) const{//Compare object with object
	if(strSize != rhs.strSize)//If the size isnt equal then its not equal
		return false;
	for(size_t i=0; i<=strSize; i++){//Compare each indiviadual elements
		if(strArray[i] != rhs.strArray[i])
			return false;	
	}
	return true;//If flase was never hit, return true
}

/***************************************************************
Function:bool NIUString::operator==() const
Parameters:const char*
Returns:bool
Notes:Compare object to char*
***************************************************************/ 

bool NIUString::operator==(const char* rhs) const{//Compare object to char*
	if(strSize != strlen(rhs))//If size doesn't mathc then they are not equal
		return false;
	for(size_t i=0; i<=strSize; i++){//Compare individual elements
		if(strArray[i] != rhs[i])
			return false;
	}
	return true;//If equal return true
}

/***************************************************************
Function:const char& NIUStringoperator[]() const
Parameters:size_t
Returns:const char&
Notes:Returns subscript of strArray
***************************************************************/ 

const char& NIUString::operator[](size_t pos) const{
	return strArray[pos]; //Returns subcript of const strArray
}

/***************************************************************
Function:char& NIUString::operator[]()
Parameters:size_t
Returns:char&
Notes:returns subscript of strArray
***************************************************************/ 

char& NIUString::operator[](size_t pos){
	return strArray[pos]; //Returns subscriupt of strArray
}

/***************************************************************
Function:ostream& operator<<()
Parameters:ostream&, const NIUString&
Returns:ostream&
Notes:Diplays object
***************************************************************/ 

ostream& operator<<(ostream& lhs, const NIUString& rhs){//Displays object passed in
	for(size_t i=0; i<rhs.strSize; i++){
		lhs <<  rhs.strArray[i]; //Displays subcript of object
	}
	return lhs;//Return lhs for it to work properly
}

/***************************************************************
Function:bool operator==()
Parameters:const char*, const NIUString&
Returns:bool
Notes:Compares char* to object
***************************************************************/ 

bool operator==(const char* lhs, const NIUString& rhs){ //Compares char* to object
	if(strlen(lhs) != rhs.strSize) //If size isn't equal then they aren't equal
		return false;
	for(size_t i = 0; i < rhs.strSize; i++){//Compare each individual element of arrays
		if(lhs[i] != rhs.strArray[i])
			return false; 
	}
	return true;//Return true if no flase return were hit(meaning everything was equal)
	
}

//Rxtra credit:

/*******************************************************************
 *Function:NIUString::NIUString()
 *parameter:NIUString&&
 *return:NIUString
 * ****************************************************************/
NIUString::NIUString(NIUString&& other){
	strSize=other.strSize;
	cap=other.cap;
	strArray = other.strArray;  //Set values from other and reset other
	other.strSize=0;
	other.cap=0;
	other.strArray = nullptr;
}
/****************************************************************
 *Function: NIUString& NIUString::operator=()
 *Parameter:NIUString&&
 *return:NIUString
 * *************************************************************/
NIUString& NIUString::operator=(NIUString&& other){
	if(this != &other){
		delete[] strArray;
		cap=other.cap;
		strSize=other.strSize;
		strArray=other.strArray; //set values from other, reset other
		other.strSize=0;
		other.cap=0;
		other.strArray = nullptr;
	}	
	return *this;
}
		
