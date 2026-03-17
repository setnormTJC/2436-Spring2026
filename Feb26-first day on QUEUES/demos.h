#pragma once
#include "QueueADT.h"


namespace Demos
{
	void demoLinkedListFunctionality()
	{
		LinkedList ll("Alice");

		ll.pushFront("Bob");

		ll.pushFront("Carol");

		ll.pushFront("Darth");

		ll.pushFront("Eve");

		ll.pushFront("Franco"); //this person is an ITALIAN

		ll.popFront();

		ll.pushBack("Zebra");

	}

	void simpleQueueDemo()
	{
		//std::queue<std::string> customersInLine;

		//QueueADT q; 

		QueueImplementedWithLinkedList q("Alice");

		q.push("Bob");

		q.push("Carol");

		q.push("Darth");

		q.pop();
	}



}

