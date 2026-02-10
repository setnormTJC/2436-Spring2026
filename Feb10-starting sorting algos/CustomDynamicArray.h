#pragma once

#include<string> 
#include<vector> 

class CustomDynamicArray
{

public:
	std::vector<std::string> listOfStrings; 



	CustomDynamicArray() = default; 

	CustomDynamicArray(const std::vector<std::string>& listOfStrings); 

	void print(); 

	bool isSortedInAscendingOrder();



	/*This algorithm has complexity BigO(INFINTITY)*/
	void miracleSort(); 

	/*THis is O(N!) complexity*/
	void monkeySort(); 

	/*This algo is O(N^2) complexity ON AVERAGE (BEST case: O(N))*/
	void naiveSort(); 

};

