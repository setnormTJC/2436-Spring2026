#include "QueueADT.h"

#include<iostream> 



#pragma region Linked-list-based queue
QueueImplementedWithLinkedList::QueueImplementedWithLinkedList(std::string dataAtFrontOfQueue)
	: 
	linkedList(dataAtFrontOfQueue)
{
	//nothing needed here
}

void QueueImplementedWithLinkedList::push(std::string newValue)
{
	linkedList.pushBack(newValue); 
}

void QueueImplementedWithLinkedList::pop()
{
	//if queue is EMPTY - go no further! 

	linkedList.popFront(); 
}
#pragma endregion 



#pragma region Array-based queue

QueueImplementedWithArray::QueueImplementedWithArray(std::string dataAtFrontOfQueue)
{

}

void QueueImplementedWithArray::pop()
{
	//QueueImplementedWithArray::array.p
}

#pragma endregion 