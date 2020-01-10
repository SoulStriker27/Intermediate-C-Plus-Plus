/***********************************************************************
Programmer: Eduardo Leanos
Porpuse: exercise in implementing the stack ADT using a singly-linked list
***********************************************************************/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <ostream>


using namespace std;

template <class T> //The Struct Node
struct Node{
	T data; //The Data
	Node<T>* next; //Pointer to next node
	Node(const T& = T(), Node<T>* next = nullptr); //Constructor
};

template <class T>
Node<T>::Node(const T& data, Node* next){ //Constructor
	this->data = data; //Set Data to passed in Data
	this->next = next; //Set next to the next pointer
}

template <class T> //Declare Stack class to use it in operator=
class Stack;

template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

template <class T> //The Stack Class
class Stack{
	private:  //Data members
		Node<T>* stkTop;
		size_t stkSize;
		void copyList(const Stack<T>&);
	public:
		Stack(); //Constructor
		~Stack(); //Deconstructor
		Stack(const Stack<T>&); //Copy constructor
		Stack<T>& operator=(const Stack<T>&); //Assigment operator
		friend ostream& operator<< <>(ostream&, const Stack<T>&);
		void clear();
		size_t size()const;
		bool empty()const;
		const T& top()const;
		void push(const T&);
		void pop();	
};

/***************************************************************
Function: Stack<T>::Stack()
Parameters:None
Returns:Nothing
Notes:Constructor
***************************************************************/ 

template <class T>
Stack<T>::Stack(){
	stkTop = nullptr; //Set to Null
	stkSize = 0;
}

/***************************************************************
Function:Stack<T>::~Stack()
Parameters:None
Returns:Nothing
Notes:Deconstructor
***************************************************************/ 

template <class T>
Stack<T>::~Stack(){ //Call clear
	clear();
}

/***************************************************************
Function:Stack<T>::Stack(const Stack<T>& other)
Parameters:const Stack<T>& other
Returns:None
Notes:Copy constructor
***************************************************************/ 

template <class T>
Stack<T>::Stack(const Stack<T>& other){ 
	stkTop = nullptr; //Makes a ptr
	copyList(other); //Copies nodes to ptr
	stkSize = other.stkSize; //copies size
}

/***************************************************************
Function:Stack<T>& Stack<T>::operator=(const Stack<T>& other)
Parameters:const stack<T>& other
Returns:Stack<T>&
Notes:Assigment operator
***************************************************************/ 

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other){
	if(this != &other){ //Compares obects to each other, for self assigment
		clear(); //Call clear to reset Nodes
		copyList(other); //Copies Nodes
		stkSize = other.stkSize; //Copies size
	}
	return *this; //Return Stack<T>&
}

/***************************************************************
Function: ostream& operator<<(ostream& lhs, const Stack<T>& rhs)
Parameters:ostream&, and const Stack<T>& rhs
Returns:ostream&
Notes:Output operator
***************************************************************/ 

template <class T>
ostream& operator<<(ostream& lhs, const Stack<T>& rhs){
	Node<T>* ptr;

	for(ptr = rhs.stkTop; ptr != nullptr; ptr = ptr->next) //For all Nodes
		lhs << ptr->data << ' '; //Display Data
	return lhs;
}

/***************************************************************
Function:void Stack<T>::clear()
Parameters:None
Returns:None
Notes:Call pop until it is empty
***************************************************************/ 

template <class T>
void Stack<T>::clear(){
	while(!empty()){
		pop(); //Call pop to clear
	}
}

/***************************************************************
Function:size_t Stack<T>::size()const
Parameters:None
Returns:size_t 
Notes:Return the stkSize of Node object
***************************************************************/ 

template <class T>
size_t Stack<T>::size()const{
	return stkSize; //Return stkSize
}

/***************************************************************
Function:bool Stack<T>::empty()
Parameters:None
Returns:Bool
Notes:If the stack is empty return true, if not return false
***************************************************************/ 

template <class T>
bool Stack<T>::empty()const{ //Check if objects empty
	if(stkSize ==0)
		return true;
	return false;
}

/***************************************************************
Function:const T& Stack<T>::top()const
Parameters:None
Returns:const T&
Notes:Return the data from the top of the Stack
***************************************************************/ 

template <class T>
const T& Stack<T>::top()const{ //Return Data
	if ( stkSize == 0)
		throw "Stack underflow Top";
	return stkTop->data;
}

/***************************************************************
Function:void Sack<T>::push(const T& cal)
Parameters:const T& cal
Returns:Nothing
Notes:Pushes* a Node into the Top of the stack
***************************************************************/ 

template <class T>
void Stack<T>::push(const T& val){
	Node<T>* newNode = new Node<T>(val, stkTop); //Make new node 
	
	stkTop = newNode; //stkTop now points to the newNode
	stkSize++; //Increases stkSize
}

/***************************************************************
Function:void Stack<T>::pop()
Parameters:None
Returns:Nothing
Notes:Removes Top of stack and puts the pointer to the next part of linked list
***************************************************************/ 

template <class T>
void Stack<T>::pop(){
	if(stkSize == 0)
		throw "Stackunderflow Pop";
	Node<T>* delNode = stkTop; //Make a delNode to stkTop
	stkTop = stkTop->next; //Set stkTop to the next part of linked list

	delete delNode; //Delete delNode
	stkSize--;//Decrease stkSize
}

/***************************************************************
Function:void Stack<T>copyList(const Stack<T>& other)
Parameters:const Stack<T> other
Returns:Nothing
Notes:Copies all Nodes from the caller of the parameter to the
object that called the method
***************************************************************/ 

template <class T>
void Stack<T>::copyList(const Stack<T>& other){
	Node<T>* ptr, *newNode, *last = nullptr; //Make muliple pointers

	for (ptr = other.stkTop; ptr != nullptr; ptr = ptr->next){ //For All the Nodes inputed, cancel at nullptr
		newNode = new Node<T>(ptr->data); //Set newNode to dynamic ptr of current Node
						 //This sets Data into new node, while it having a dynamically located storage

		if( last == nullptr) //If last still equals nullptr
			stkTop = newNode; //Set StkTop to newNOde
		else
			last->next = newNode; //Set ptr of Last->next to newNode
		
		last = newNode; //Set last ptr to newNode
	}
}

#endif
