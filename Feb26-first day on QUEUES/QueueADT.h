#pragma once

#include"../Feb19-first day on linked lists/LinkedList.h" //NOTE! LinkedList.cpp MUST be added to this project for this to work!
//(Right-click on this project, add EXISTING, navigated to LinkedList.cpp)
//This creates a linked file (heh). In some ways, this is better than copying
#include<string> 
#include <vector>

/*Abstract data type!*/
class QueueADT
{
public: 
	/*this is a "pure virtual function" - takeaway is: objects of this ABSTRACT CLASS cannot be instantiated*/
	
	/*Post condition: the newValue is at the BACK of the line! FIFO -> First in, first out (also called FCFS)*/
	virtual void push(std::string newValue) = 0; //what is this called?! This is a special type of C++ function. 

	virtual void pop() = 0;//another "pure virtual func." 
};



class QueueImplementedWithLinkedList : public QueueADT
{
	//NOTE: the parent class's `push` function MUST be implemented here (if you plan to instantiate this class) 
private: //outsiders can't touch the privates! (hide the implementation details - don't overwhelm with complexity) 
	//COMPOSE this class of a linked list object!
	LinkedList linkedList; //this is composition! (this could be described as the underlying implementation) 

public: 
	QueueImplementedWithLinkedList() = delete; 
	QueueImplementedWithLinkedList(std::string dataAtFrontOfQueue); 

	/*Push inserts in rear*/
	void push(std::string newValue) override;
	/*Pop removes from front - BECAUSE FIFO (first in, first out) "scheduling policy"*/
	void pop() override; 
};


class QueueImplementedWithArray : public QueueADT
{

	std::vector<std::string> dynamicArray; //what about this is no good for a seque (single-ended queue)?

public: 
	QueueImplementedWithArray() = delete; 
	QueueImplementedWithArray(std::string dataAtFrontOfQueue);

	//void push(std::string newValue) override;
	void pop() override;
	
};
