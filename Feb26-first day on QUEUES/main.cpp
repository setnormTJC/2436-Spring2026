// Feb26-first day on QUEUES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue> 

#include"QueueADT.h"

using namespace std; 

void printCustomers(std::queue<std::string> customersInLine)
{
    while (customersInLine.empty() == false)
    {
        cout << customersInLine.front() << "\n";
        customersInLine.pop(); //pop removes the element (customer) from the front of the queue
    }
}

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

int main()
{
    std::queue<std::string> customersInLine; 

    //QueueADT q; 

    QueueImplementedWithLinkedList q("Alice");

    q.push("Bob"); 

    q.push("Carol");

    q.push("Darth");

    q.pop(); 
}

