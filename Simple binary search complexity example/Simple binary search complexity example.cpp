// Simple binary search complexity example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


int binarySearch(std::vector<int> sortedNums, int searchValue)
{
	bool found = false;
	int first = 0;
	int last = sortedNums.size() - 1;
	int middle;
	
	int comparisonCount = 0; //this metric is what pretty much all comp. sci. classes use rather than TIMING

	while (first <= last and !found)
	{
		comparisonCount++; //this is a SIMPLE method of doing algorithm analysis

		middle = (first + last) / 2; //use ceil() or floor() for odd lengths … be cautious
		if (sortedNums[middle] == searchValue)
		{
			found = true;
		}
		else if (sortedNums[middle] > searchValue)
		{
			last = middle - 1;//shift last one to the "left" of middle
		}
		else
		{
			first = middle + 1;
		}
	} //end while 


	const int FUDGE_FACTOR = 1; 

	if (found)
	{
		std::cout << "Total comparisons for N = " << sortedNums.size() << " : " << comparisonCount - FUDGE_FACTOR << "\n";
 		return middle;
	}
	else
	{
		std::cout << "Total comparisons for N = " << sortedNums.size() << " : " << comparisonCount - FUDGE_FACTOR << "\n";
		return -1;//element is not in array
	}
}

int main()
{
	std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int maxValue = *std::max_element(nums.begin(), nums.end());
	binarySearch(nums, maxValue);


	std::vector<int> nums64;
	for (int i = 1; i <= 64; i++) {
		nums64.push_back(i);
	}
	std::vector<int> nums1024;
	for (int i = 1; i <= 1024; i++) {
		nums1024.push_back(i);
	}

	binarySearch(nums64, 64);
	binarySearch(nums1024, 1024);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
