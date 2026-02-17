// Feb10-starting sorting algos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<algorithm>
#include <iostream>
#include<random>

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
   
    customDynamicArray.quickSort(0, customDynamicArray.listOfStrings.size() - 1);


    std::cout << "\n\nDid it work (shivers in anticipation):\n";
    std::system("pause"); 
    customDynamicArray.print(); 

    //std::cout << "Hello World!\n";
}
