// Feb19-first day on linked lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<forward_list> //forward means traversal (going through) the list is only possible in the "forward" direction (SINGLY-linked list)
#include <iostream>
#include "LinkedList.h"



int main()
{
	//DON'T!
	//while (true)
	//{
	//	int* i = new int; //dynamically allocates 4 Bytes of memory INFINITELY 
	//}


	std::cout << "Size of a POINTER (the memory address of) a Node object " << sizeof(Node*) << "\n";
	std::cout << "Size of Node object (the amount of memory that NEW will allocate" << sizeof(Node) << "\n";

	Node* pHead = new Node; //beware! of nullptr exceptions! (will the teacher generate one - many - YES!)

	pHead->data = "whiskey";

	pHead->pNext = nullptr; //but why!? (because this linked list is LAME - only one node)


	/*Add the second NODE - hooray!*/

	Node tailNode; 
	//tailNode.data = "tango"
	
	Node* pTail = &tailNode; //the ampersand in this case acts as UNARY operator that gets the address of tailNode

	pTail->data = "tango";
	

	pHead->pNext = pTail; //tadaa! A linked consisting of 2 nodes is now made!

}

