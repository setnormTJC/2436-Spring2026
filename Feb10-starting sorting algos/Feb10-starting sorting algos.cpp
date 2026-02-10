// Feb10-starting sorting algos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<algorithm>
#include <iostream>


#include "CustomDynamicArray.h"

int main()
{
    std::vector<std::string> names =
    {
        "Diego",
        "Cierra",
        "Michael",
        "Jewels",
        "Samuel",
        "Jonathan"
    };

    CustomDynamicArray customDynamicArray(names); 

    std::cout << "UNSORTED names:\n";
    customDynamicArray.print(); 

    //std::is_sorted()


    std::sort(customDynamicArray.listOfStrings.begin(), customDynamicArray.listOfStrings.end());
    
    customDynamicArray.miracleSort(); 

    
    std::cout << "SORTED names:\n";
    customDynamicArray.print();

    //std::cout << "Hello World!\n";
}
