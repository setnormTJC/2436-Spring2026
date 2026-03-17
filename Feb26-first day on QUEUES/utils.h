#pragma once
#include <queue>
#include <string>
#include <iostream>
#include "QueueADT.h"


using namespace std; 

void printCustomers(std::queue<std::string> customersInLine)
{
    while (customersInLine.empty() == false)
    {
        cout << customersInLine.front() << "\n";
        customersInLine.pop(); //pop removes the element (customer) from the front of the queue
    }
}


