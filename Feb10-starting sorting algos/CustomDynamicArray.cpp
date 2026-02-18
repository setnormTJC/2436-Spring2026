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
				//print();//print updated array for visualization:
				//std::system("pause"); 
			}
		}
		//std::cout << "Incrementing LEFT index to: " << leftIndex + 1 << "\n";
	}
}


int CustomDynamicArray::partition(int low, int high)
{
	std::string pivot = listOfStrings[high];
	//std::cout << "Pivoting around " << pivot << " ...\n";
	int i = low - 1;

	for (int j = low; j < high; ++j)
	{
		if (listOfStrings[j] <= pivot)
		{
			++i; //move the "boundary" of elements that are less than the pivot: 
			std::swap(listOfStrings[i], listOfStrings[j]);
		}
	}

	std::swap(listOfStrings[i + 1], listOfStrings[high]);

	//std::cout << "Updated names after partition: \n";
	//print(); 

	return i + 1; //new partition location is 1 step to the right of the last element less than the pivot  
}

void CustomDynamicArray::quickSort(int low, int high)
{
	//static int pivotCounter = 0;

	if (low < high)
	{
		int pivot = partition(low, high);
		//pivotCounter++;

		////If wanting to hide complexity/detail of partition function:
		////the std library way uses std::paritition and is something close to: 
		//auto partitionLoc = std::partition(names.begin() + 0, names.end() - 1,
		//	[&](const std::string& currentName)
		//	{
		//		return currentName < names.back();
		//	});
		quickSort( low, pivot - 1);
		quickSort(pivot + 1, high); //NOTE the exclusion of the pivot in BOTH of these recursive calls
	}

	//for algo analysis: 
	//if (std::is_sorted(names.begin(), names.end()))
	//{
	//	std::cout << "Pivot counter: " << pivotCounter << "\n";
	//}
}
