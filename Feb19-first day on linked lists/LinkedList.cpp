#include"LinkedList.h"

#include<iostream> 

using namespace std; 

LinkedList::LinkedList(std::string dataInFrontNode)
{
	pHead = new Node(dataInFrontNode, nullptr);
	//what do it do? 

	pTail = pHead;
}

void LinkedList::pushFront(std::string newData)
{
	//first, make the new node!
	Node* pNew = new Node(newData, nullptr);

	pNew->pNext = pHead;

	/*Don't lose your head!*/
	pHead = pNew;

	/*Is any updated needed to pTail?? (I think not!)*/
}

//void LinkedList::pushBack(std::string newData)
//{
//	Node* pTemp = pHead; 
//
//	int numberOfOperations = 0; //by "operations", I mean having to advance the pointer
//
//	while (pTemp->pNext != nullptr)
//	{
//		pTemp = pTemp->pNext; //i++
//		numberOfOperations++; 
//	}
//
//	Node* pNew = new Node(newData, nullptr);
//
//	pTemp->pNext = pNew; 
//
//	delete pTemp; 
//
//	std::cout << "We had to do this many operations for pushing back " << newData << ": " << numberOfOperations << "\n";
//}

void LinkedList::pushBack(std::string newData)
{
	Node* pNew = new Node(newData, nullptr);
	pTail->pNext = pNew;
	pTail = pNew;

	//No longer O(N) now that we have added SPACE COMPLEXITY (pTail)  - hooray!
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
