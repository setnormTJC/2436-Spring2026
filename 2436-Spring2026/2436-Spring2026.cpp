/*
* This program will search for a student in this room (efficiently AND inefficiently)!
*/

#include "CustomDynamicArray.h"
#include<algorithm> //included so we have access to std::is_sorted (among other functions) 
#include<chrono>
#include<iomanip> //for std::scientific
#include <iostream>


void someTimingWork()
{

	auto startTime = std::chrono::high_resolution_clock::now();

	/*Question: how long does it take C++ to count to 1 billion?*/
	for (int i = 0; i < 1'000'000; ++i)
	{
		//do nothing (aren't you being MEAN to your computer ...)
	}
	auto stopTime = std::chrono::high_resolution_clock::now();

	std::cout << "It took this many nanoseconds (billionths of a second): \n";


	auto theTimeItTook = (stopTime - startTime).count();

	std::cout << std::fixed << std::setprecision(2);
	std::cout << std::scientific << (float)theTimeItTook << "\n";

}



int main()
{

	std::string theNameToSearchFor;


	std::string filenameForStudentRoster = "studentRoster.csv";
	CustomDynamicArray students(filenameForStudentRoster);

	/*Let's do a selection search for a random name in this list*/
	students.print();

	auto randomStudent = students.getRandomStringInList();


	std::cout << "\n\n\n";
	std::cout << "Searching for: " << randomStudent << "\n";
	if (students.binarySearch(randomStudent, 0, students.listOfStrings.size() - 1))
	{
		std::cout << "FOUND that student\n";
	}

	else
	{
		std::cout << "NOT found\n";
	}
}

