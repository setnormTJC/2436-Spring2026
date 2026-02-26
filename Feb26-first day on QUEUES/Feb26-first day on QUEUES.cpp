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

int main()
{
    std::queue<std::string> customersInLine; 


    //customersInLine.pop(); //no inputs/args/params

    //customersInLine.push("Blake");
    //customersInLine.push("Diego");
    //customersInLine.push("Jewels");
    //customersInLine.push("Michael");
    //customersInLine.push("Samwise");

    //printCustomers(customersInLine);

    //QueueADT q; 

    QueueFromLinkedList q; 


}

