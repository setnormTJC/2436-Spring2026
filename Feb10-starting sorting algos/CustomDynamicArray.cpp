#include "CustomDynamicArray.h"
#include <iostream>
#include <algorithm>
#include <random>

CustomDynamicArray::CustomDynamicArray(const std::vector<std::string>& listOfStrings)
	: 
	listOfStrings(listOfStrings)
{

}

void CustomDynamicArray::print()
{
	for (int i = 0; i < listOfStrings.size(); ++i)
	{
		std::cout << listOfStrings[i] << " ";
	}
	std::cout << "\n";
}

bool CustomDynamicArray::isSortedInAscendingOrder()
{
	//return (std::is_sorted(listOfStrings.begin(), listOfStrings.end()));
	bool sorted = true;

	for (int i = 0; i < listOfStrings.size() - 1; ++i)
	{
		if (listOfStrings[i + 1] < listOfStrings[i])
		{
			sorted = false;
		}
	}
	return sorted;
}

void CustomDynamicArray::miracleSort()
{
	while (!isSortedInAscendingOrder())
	{
		//PRAY! (to Zeus)
		print(); 
	}
	//do NOTHING
}

void CustomDynamicArray::monkeySort()
{
	//fill me in! (with shuffling until sorted)

	std::mt19937 rng(std::random_device{}());

	int shuffleCount = 0; 

	while (!isSortedInAscendingOrder())
	{
		std::shuffle(listOfStrings.begin(), listOfStrings.end(), rng);
		print(); 
		shuffleCount++; 
	}

	std::cout << "It took this many shuffles to sort (get lucky): " << shuffleCount << "\n";
}

void CustomDynamicArray::naiveSort()
{
	for (int leftIndex = 0; leftIndex < listOfStrings.size() - 1; leftIndex++)
	{
		for (int rightIndex = leftIndex + 1; rightIndex < listOfStrings.size(); rightIndex++)
		{
			if (listOfStrings[leftIndex] > listOfStrings[rightIndex])//then swap
			{
				std::swap(listOfStrings[leftIndex], listOfStrings[rightIndex]);
				print();//print updated array for visualization:
				std::system("pause"); 
			}
		}
		std::cout << "Incrementing LEFT index to: " << leftIndex + 1 << "\n";
	}
}
