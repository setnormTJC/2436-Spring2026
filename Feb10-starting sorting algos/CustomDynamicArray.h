#pragma once

#include<string> 
#include<vector> 

/*Wrapper around std::vector that adds some functionality*/
class CustomDynamicArray
{

public:
	std::vector<std::string> listOfStrings; 

	CustomDynamicArray() = default; 

	CustomDynamicArray(const std::vector<std::string>& listOfStrings); 

	void print(); 

	/*Mr. Wright implemented this bad boy, so it is PERFECT (without bugs)*/
	bool isSortedInAscendingOrder();

	/*This algorithm has complexity BigO(INFINTITY)*/
	void miracleSort(); 

	/*THis is O(N!) complexity*/
	void monkeySort(); 

	/*This algo is O(N^2) complexity ON AVERAGE (BEST case: O(N))*/
	void naiveSort(); 

	/*low must be 0, and high must be N - 1??? (or N or N +1)*/
	void quickSort(int low, int high);

	int partition(int low, int high);
};

