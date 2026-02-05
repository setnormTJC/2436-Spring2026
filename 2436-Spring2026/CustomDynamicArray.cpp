#include "CustomDynamicArray.h"


#include<algorithm>
#include<fstream>
#include <iostream>
#include<random> 

CustomDynamicArray::CustomDynamicArray(const std::string& filename)
{
	std::ifstream fin(filename);

	if (!fin)
	{

		std::cout << "Could not find the file named " << filename << "\n";
		__debugbreak();
	}

	std::string currentStudentName;
	while (std::getline(fin, currentStudentName))
	{
		//std::cout << currentStudentName << "\n";
		listOfStrings.push_back(currentStudentName);
	}

}

void CustomDynamicArray::shuffle()
{

	std::mt19937 rng(std::random_device{}()); //this syntax is CRAZY (let's just use "abstraction")
	std::uniform_int_distribution<int> distribution(0, listOfStrings.size() - 1);

	for (int i = 0; i < listOfStrings.size(); ++i)
	{
		int randomIndex = distribution(rng);

		if (randomIndex < 0 || randomIndex > listOfStrings.size() - 1)
		{
			std::cout << "Out of bounds\n";
			__debugbreak();
		}

		std::swap(listOfStrings[i], listOfStrings[randomIndex]);
	}
}

void CustomDynamicArray::print()
{
	for (const std::string& currentString : listOfStrings)
	{
		std::cout << currentString << "\n";
	} //Heisenbug
}

std::string CustomDynamicArray::getRandomStringInList()
{
	std::mt19937 rng(std::random_device{}()); //this syntax is CRAZY (let's just use "abstraction")
	std::uniform_int_distribution<int> distribution(0, listOfStrings.size() - 1);
	int randomIndex = distribution(rng);

	//int otherRandomIndex = rand() % listOfStrings.size(); //this is a SIMPLER (but less "good") version 
															//of the 3 lines directly above

	std::string randomString = listOfStrings[randomIndex];

	return randomString; //fix me!
}

bool CustomDynamicArray::sequentialSearch(const std::string& targetString)
{

	std::cout << "We are looking for: " << targetString << "\n";

	for (int i = 0; i < listOfStrings.size(); ++i)
	{
		if (listOfStrings[i] == targetString) //the droid we're looking for
		{
			return true; //found
		}
	}

	return false;
}

//bool CustomDynamicArray::binarySearch(const std::string& targetString, int low, int high)
//{
//
//	if (low >= high)
//	{
//		std::cout << targetString << " not found!\n";
//		return false;
//	}
//	int mid = floor((high + low) / 2); 
//
//	if (listOfStrings[mid] == targetString)
//	{
//		return true; //"base" case in this recursive function (prevents "infinite recursion" (stack overflow)
//	}
//
//	else if (listOfStrings[mid] > targetString)
//	{
//		high = mid - 1;
//		return binarySearch(targetString, low, high);//recursive call
//	}
//
//	else //value at middle position must be < target string
//	{
//		low = mid + 1;
//		return binarySearch(targetString, low, high); //recursive call
//	}
//}


bool CustomDynamicArray::binarySearch(const std::string& targetString, int low, int high)
{
	// Fix 1: The condition must be low > high. 
	// If low == high, we still need to check that last element!
	if (low > high)
	{
		std::cout << targetString << " not found!\n";
		return false;
	}

	// Standard integer division in C++ handles the "floor" automatically
	int mid = low + (high - low) / 2;

	if (listOfStrings[mid] == targetString)
	{
		return true;
	}
	else if (listOfStrings[mid] > targetString)
	{
		// Target is in the left half
		return binarySearch(targetString, low, mid - 1);
	}
	else
	{
		// Target is in the right half
		return binarySearch(targetString, mid + 1, high);
	}
}