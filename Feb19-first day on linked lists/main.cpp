// Feb19-first day on linked lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<forward_list> //forward means traversal (going through) the list is only possible in the "forward" direction (SINGLY-linked list)
#include <iostream>
#include "LinkedList.h"



Node* demoThreeNodeLinkedList()
{
	Node* pHead = new Node; //beware! of nullptr exceptions! (will the teacher generate one - many - YES!)

	pHead->data = "whiskey"; //prepone

	pHead->pNext = nullptr;


	//std::cout << pHead->pCurrent << '\n';
	//std::cout << pHead->data->p;


	/*Add the second NODE - hooray!*/

	//Node secondNode; //static memory allocation (versus dynamic)
	//tailNode.data = "tango"

	Node* pSecond = new Node; // &secondNode; //the ampersand in this case acts as UNARY operator that gets the address of tailNode

	pSecond->data = "tango";

	pHead->pNext = pSecond; //tadaa! A linked consisting of 2 nodes is now made!

	/*Add a THIRD node!*/

	//DANGER, Will Robinson! (don't go out of bounds -> similar to accessing index = -1 in an ARRAY
	//std::cout << pHead->pNext->pNext->data;

	Node* pTail = new Node; 

	pTail->data = "foxtrot";

	//LINK this 3rd node back to the second node: 
	pSecond->pNext = pTail; 
	
	pTail->pNext = nullptr; 

	return pHead;
}

void printLinkedList(Node* pHead)
{
	Node* pCurrent = pHead; 

	while (pCurrent != nullptr)
	{
		std::cout << pCurrent->data; 

		//instead of i++ -> which we would do for an ARRAY
		pCurrent = pCurrent->pNext;
	}
}


int main()
{

	
	std::forward_list<std::string> forwardList; 
	//forwardList.pu
	//forwardList.p
	
	//Node* pHead = demoThreeNodeLinkedList(); 

	//printLinkedList(pHead);
	LinkedList linkedList("Alice");

	linkedList.pushFront("Bob");

	linkedList.pushFront("Carol");

	linkedList.pushFront("Darth");

	linkedList.print(); 

	
}

