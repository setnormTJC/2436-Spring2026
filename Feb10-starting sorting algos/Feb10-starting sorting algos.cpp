// Feb10-starting sorting algos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<algorithm>
#include<chrono>
#include<fstream>
#include<iomanip>
#include <iostream>
#include<random>
#include<string> 

#include "CustomDynamicArray.h"


void sortingASMALLArray()
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

}


std::vector<std::string> readAlbanianDictionary()
{
    std::string filename = "C:/Users/Work/Downloads/shqip.csv";

    std::ifstream fin(filename); 

    if (!fin)
    {
        std::cout << filename << " not found\n";
        return {};
    }


    std::vector<std::string> albanianWords; 

    std::string currentAlbanianWord; 
    while (std::getline(fin, currentAlbanianWord))
    {
        albanianWords.push_back(currentAlbanianWord);
    }

    return albanianWords; 
}

int main()
{

    //std::map<std::string, std::string> albanianToEnglish; 

    std::vector<std::string> albanianLexicon = readAlbanianDictionary(); 

    std::mt19937 rng(std::random_device{}());

    std::shuffle(albanianLexicon.begin(), albanianLexicon.end(), rng); 

    CustomDynamicArray customDynamicArray(albanianLexicon);


    bool isSorted = std::is_sorted(customDynamicArray.listOfStrings.begin(), customDynamicArray.listOfStrings.end());


    auto start = std::chrono::high_resolution_clock::now(); 

    customDynamicArray.naiveSort(); 

    //customDynamicArray.quickSort(0, albanianLexicon.size() - 1); 

    auto stop = std::chrono::high_resolution_clock::now();




    std::cout << std::fixed << std::setprecision(2) << std::scientific; 

    std::cout << "It took this many nanoseconds: "; 
    std::cout << (float)(stop - start).count() << "\n";

    std::system("pause"); 

    isSorted = std::is_sorted(customDynamicArray.listOfStrings.begin(), customDynamicArray.listOfStrings.end());

    int a; 


    //customDynamicArray.quickSort(); 

    //std::cout << "Hello World!\n";
}
