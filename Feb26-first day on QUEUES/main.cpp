// Feb26-first day on QUEUES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iomanip> 
#include <iostream>
#include<queue> 

#include"demos.h"
#include"QueueADT.h"
#include"utils.h"

using namespace std; 


struct PrinterJob
{
	std::string owner; //ex: Bob
	int pageCount; 

	int pagesPrintedSoFar = 0; //this will get incremented by an external function  

	bool isDone()
	{
		if (pagesPrintedSoFar - pageCount == 0)
		{
			return true; 
		}

		else
		{
			return false; 
		}
	}
};


void displayPrintQueue(std::queue<PrinterJob> printerJobs)
{

	const int OWNER_COL_WIDTH = 20; 
	const int PAGES_PRINTED_COL_WIDTH = 15;
	const int TOTAL_PAGES_COL_WIDTH = 15;



	cout << left << setw(OWNER_COL_WIDTH) << "Job owner"; 
	cout << left << setw(PAGES_PRINTED_COL_WIDTH) << "Pages printed";
	cout << left << setw(TOTAL_PAGES_COL_WIDTH) << "total pages";
	cout << "\n";

	while (printerJobs.empty() == false)
	{
		cout << left << setw(OWNER_COL_WIDTH) << printerJobs.front().owner;
		cout << left << setw(PAGES_PRINTED_COL_WIDTH) << printerJobs.front().pagesPrintedSoFar; //use std::setw
		cout << left << setw(TOTAL_PAGES_COL_WIDTH) << printerJobs.front().pageCount;
		cout <<"\n";

		printerJobs.pop(); //not to be confused with an energy drink (or Coke)
	}
}


void processJobs(std::queue<PrinterJob>& printerJobs) //you passed by value! Bad boy! Gotcha
{
	//increment the number of pages printed so far (while !isDone)

	while (!printerJobs.empty())
	{
		cout << "Getting job from owner: " << printerJobs.front().owner << "\n";
		cout << "Printed all " << printerJobs.front().pageCount << " of this job\n";

		printerJobs.pop(); 


	}

}



int main()
{
	
	std::queue<PrinterJob> printerJobs; 

	printerJobs.push({ "Cielo Almanza", 3 });

	printerJobs.push({ "Samuel George", 6 });

	printerJobs.push({ "Michael Wright", 8 });



	displayPrintQueue(printerJobs); 

	processJobs(printerJobs); 

	//cout << "Did it work?\n";


	//can we add in the concept of PRIORITY here? 

}

