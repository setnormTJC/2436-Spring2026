#include "QueueADT.h"

#include<iostream> 

LinkedList::LinkedList(std::string dataInFrontNode)
{
	pHead = new Node(dataInFrontNode, nullptr);
	//what do it do? 
}

void LinkedList::pushFront(std::string newData)
{
	//first, make the new node!
	Node* pNew = new Node(newData, nullptr);

	pNew->pNext = pHead;

	/*Don't lose your head!*/
	pHead = pNew;
}

void LinkedList::pushBack(std::string newData)
{
	Node* pTemp = pHead; 

	while (pTemp->pNext != nullptr)
	{
		pTemp = pTemp->pNext; //i++
	}

	Node* pNew = new Node(newData, nullptr);

	pTemp->pNext = pNew; 

	delete pTemp; 
}

void LinkedList::popFront()
{
	//SOMETHIGN will be done with pHead!

	//NEED a safety check here!

	Node* pTemp = pHead; //makes a copy

	pHead = pHead->pNext;

	delete pTemp; //no leak here pal!

}

void LinkedList::print()
{
	Node* pCurrent; //this is similar to i in for (int i = 0; i < array.size(); ++i){}

	pCurrent = pHead;

	while (pCurrent != nullptr)
	{
		//"visit" the current node: 
		std::cout << pCurrent->data << " ";

		//similar to i++:
		pCurrent = pCurrent->pNext;
	}
}


void QueueImplementedWithLinkedList::push(std::string newValue)
{
	//linkedList.pushFront(newValue); 
}

void QueueImplementedWithLinkedList::pop()
{
	//linkedList.popFront(); 
}
