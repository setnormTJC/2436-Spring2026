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



};

