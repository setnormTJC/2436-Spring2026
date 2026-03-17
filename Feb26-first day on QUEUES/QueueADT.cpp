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

	linkedList.popFront(); 	//THREE operations (if including delete to prevent memory leaks - not using "smart" pointers in C++)
}

#pragma endregion 



#pragma region Array-based queue

QueueImplementedWithArray::QueueImplementedWithArray(std::string dataAtFrontOfQueue)
{
	dynamicArray.push_back(dataAtFrontOfQueue); 

}

void QueueImplementedWithArray::push(std::string newValue)
{
	/*"Extra" stuff required if using a clever pop*/
	//if (dynamicArray.empty())
	//{
	//	first = 0; 
	//	last = 0; 
	//}

	//else
	//{
		//insert clever logic here ... :)
	//}

	/*The simple "core" of this method*/
	dynamicArray.push_back(newValue); 
}

void QueueImplementedWithArray::pop()
{
	//dynamicArray.pop_back(); //NOPE! -> first in, ... LAST out? (FILO?)
	
	popNaively(); //NOTE that this is a PRIVATE function (hide detail from an uninterested supervisor - just give me results! Fast!)

	//But there's GOT to be a bettah way! (Lil Troy) -> uncomment the line below: 
	//popCleverly(); 

}

void QueueImplementedWithArray::popNaively()
{
	//int operationCount = 0; //for algorithm analysis

	for (int i = 1; i < dynamicArray.size(); ++i)
	{
		dynamicArray[i - 1] = dynamicArray[i];

		//operationCount++; 
	}

	//last two customers are the same at the moment - get rid of the dupe (duplicate)
	dynamicArray.pop_back();

	//std::cout << "Operations for NAIVE pop (with array-based queue): " << operationCount << "\n";
}

void QueueImplementedWithArray::popCleverly()
{
	//int operationCount = 0; 


}

#pragma endregion 