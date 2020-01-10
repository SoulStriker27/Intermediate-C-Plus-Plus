/************************************************************
Programmer: Eduardo Leanos
Purpose: To develope a stack queue and be able to modify an
abstract data type.
************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <iomanip>
#include <stdexcept> //The underflow except #include

using namespace std;

template <class T> //name class before defining it
class Queue;

template <class T> //define ostream with template<class T> before using it as a freind function in class Queue
ostream& operator<< (ostream&, const Queue<T>&);

template <class T>//The class Queue
class Queue{
	friend ostream& operator<< <>(ostream&, const Queue<T>&); //The freind declaration of ostream
	private:
		T* qArr; //Pointer to array of template T
		size_t qCap, //Array descipters
	               qSize;
		int qFront, //Array subscript descriptors
		    qBack;
	public:
		Queue(); //The constructor
		~Queue(); //The deconstructor
		Queue(const Queue<T>&); 
		Queue<T>& operator=(const Queue<T>&);
		void clear();
		size_t size()const;
		size_t capacity()const;     //Method prototypes
		bool empty()const;          //Definitions after Class
		const T& front()const;
		const T& back()const;
		void push(const T&);
		void pop();
		void reserve(size_t);
};

/*********************************************************************
Method: Queue<T>::Queue()
Parameters:Nothing 
Return: Nothing
**********************************************************************/

template<class T>
Queue<T>::Queue(){  //Set object to default construct(empty)
	qCap = 0;
	qSize = 0;
	qArr = nullptr;
	qFront = 0;
	qBack = -1;
}

/*********************************************************************
Method: Queue<T>::~Queue()
Parameters:Nothing
Return:Nothing
**********************************************************************/
		
template<class T>
Queue<T>::~Queue(){ //Gets rid of that pesky qArr
	delete[] qArr;
}

/*********************************************************************
Method: Queue<T>::Queue(const Queue<T>& other)
Parameters:const Queue<T>&
Return:Nothing
**********************************************************************/
	
template<class T>
Queue<T>::Queue(const Queue<T>& other){ //Sets object to passed in object
	this->qSize = other.qSize;
	this->qCap = other.qCap;
	if (qCap ==0 )  //If capacity is 0, set qArr to nullptr
		this->qArr = nullptr;
	else
		this->qArr = new T[qCap];
	if(qCap != 0){ //If capacity is not 0, copy contents of passed in array to new object array
		for(size_t i = 0; i < qCap; i++)
			this->qArr[i] = other.qArr[i];
	this->qFront = other.qFront; 
	this->qBack = other.qBack; //Set all variables to passed in objects variables
	}
}

/*********************************************************************
Method: Queue<T>& Queue()::operator=(const Queue<T>& other
Parameters:const Queue<T>&
Return:A Queue<T>&
**********************************************************************/
		
template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other){ //Be able to use the = operand to assign object to each other
	if(this->qArr == other.qArr)  // Check for self assignment
		return *this;
	else{
		this->qCap = other.qCap; //Set all variables of object that called to object that was passed in 
		this->qSize = other.qSize;
		this->qFront = other.qFront;
		this->qBack = other.qBack;
		if (qSize == 0) //if Size was 0, set qArr to nullptr
			this->qArr = nullptr;
		else
			this->qArr = new T[qCap];
		for (size_t i = 0; i < this->qSize; i++) //Set passed in array to new array
			this->qArr[i] = other.qArr[i];
		return *this;
	}	
}

/*********************************************************************
Method: ostream& operator<<(ostream& lhs, const Queue<T>& rhs)
Parameters:const Queue<T>&
Return:ostream&
**********************************************************************/

template <class T>
ostream& operator<<(ostream& lhs, const Queue<T>& rhs){ //The cout operand for Queue objects 
	int current;
	size_t i = 0;
	for(current = rhs.qFront; i < rhs.qSize; ++i){ //Start at the front and go thorugh until you run out of size
		lhs << rhs.qArr[current] << ' '; //Cout << qArr[subscript]
		current = ( current + 1) % rhs.qCap; //Once you reach the end of capacity, loop around
	}
	return lhs; //Return lhs to allow ostream to be fully functional
}

/*********************************************************************
Method: void Queue<T>::clear()
Parameters:Nothing
Return:Nothing
**********************************************************************/

template <class T>
void Queue<T>::clear(){ //Clear an Queue object
	qCap = 0;
	qSize = 0;
	qFront = 0;
	qBack = -1;
	delete[] qArr;		//Delete qArr
	qArr = new T[qCap];    //Dynamically locate new qArr
}

/*********************************************************************
Method: size_t Queue<T>::size()
Parameters:Nothing
Return:Size_t
**********************************************************************/

template <class T>
size_t Queue<T>::size()const{ //Return Size
	return qSize;
}

/*********************************************************************
Method: size_t Queue<T>::capacity()
Parameters:nothing
Return:size_t
**********************************************************************/

template <class T>
size_t Queue<T>::capacity()const{ //Return capacity
	return qCap;
}

/*********************************************************************
Method: Bool Queue<T>::empty()
Parameters: nothing
Return:bool
**********************************************************************/

template <class T>
bool Queue<T>::empty()const{ //Return true if size = 0, false if not
	if (qSize == 0)
		return true;
	else
		return false;
}

/*********************************************************************
Method: const T& Queue<T>::front()
Parameters: Nothing
Return:T&
**********************************************************************/

template <class T>
const T& Queue<T>::front()const{ //Return Front value of Queue
	if(empty())
		throw underflow_error("Queue underflow on front()");
	else
		return qArr[qFront];
}

/*********************************************************************
Method: const T& Queue<T>::back()
Parameters:Nothing
Return:T&
**********************************************************************/

template <class T>
const T& Queue<T>::back()const{ //Return back value of Queue
	if(empty())
		throw underflow_error("Queue underflow on back()");
	else
		return qArr[qBack];
}

/*********************************************************************
Method: void Queue<T>::push(const T& num)
Parameters:const T&
Return:Nothing
**********************************************************************/

template <class T>
void Queue<T>::push(const T& num){ //Push/Put in value into qArr
	if( qSize == qCap ){
		if(qCap == 0) //If capacity = 0, then pass in 1 to reserve()
		      	reserve(1);
		else
			reserve((qCap * 2)); //If not 0, pass in double of capacity to reserve()
	}
	qBack = (qBack + 1) % qCap; //Back countinues thorught the array
	qArr[qBack] = num; //The value get put in to next part of array
	qSize++; //Size is increased because new value was put in
}

/*********************************************************************
Method: void Queue<T>::pop()
Parameters:Nothing
Return:Nothing
**********************************************************************/

template <class T>
void Queue<T>::pop(){ //pop/Delete value in array
	if ( empty() )
		throw underflow_error("Queue underflow on pop()");
	else{
		qFront = (qFront + 1) % qCap; //You dont fully delete the value, you just move the maker for the Front of array
		--qSize;
	}
}

/*********************************************************************
Method: void Queue<T>::reserve(size_t num)
Parameters:size_t
Return:Nothing
**********************************************************************/

template <class T>
void Queue<T>::reserve(size_t num){ //Reserve more space into array when called
	if(num < qCap || num == qCap) //Check is capacity is equal or greater than num passed in
		return;
			
	T* temp = new T[num]; //Create temp variable ptr with num capacity
	int current = qFront; //Get the front value of array
	for (size_t i = 0; i < qSize; i++){ //Loop through contents and put values into array, all
		temp[i] = qArr[current];
		current = ( current + 1) % qCap;
	}

	qCap = num; //Set all values of new array to object array
	qFront = 0;
	qBack = qSize - 1;
	delete[] qArr; //delete object array
	qArr = temp; //Create a new array called the same thins as the one we delted and point it to temp array

}

#endif
