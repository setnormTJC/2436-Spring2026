#include "CustomDynamicArray.h"
#include <iostream>
#include <algorithm>

CustomDynamicArray::CustomDynamicArray(const std::vector<std::string>& listOfStrings)
	: 
	listOfStrings(listOfStrings)
{

}


void CustomDynamicArray::print()
{
	for (int i = 0; i < listOfStrings.size(); ++i)
	{
		std::cout << listOfStrings[i] << "\n";
	}
}

bool CustomDynamicArray::isSortedInAscendingOrder()
{
	return (std::is_sorted(listOfStrings.begin(), listOfStrings.end()));
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
