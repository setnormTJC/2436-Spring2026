// Feb26-first day on QUEUES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

	int pagesPrintedSoFar = 124123; 

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
	while (printerJobs.empty() == false)
	{
		cout << printerJobs.front().owner << "\t" << printerJobs.front().pagesPrintedSoFar << "\n";

		printerJobs.pop(); //not to be confused with an energy drink (or Coke)
	}
}


void processJobs(std::queue<PrinterJob> printerJobs)
{
	//increment the number of pages printed so far (while !isDone)
}

int main()
{
	
	std::queue<PrinterJob> printerJobs; 

	printerJobs.push({ "Cielo Almanza", 3 });

	printerJobs.push({ "Samuel George", 6 });

	printerJobs.push({ "Michael Wright", 8 });

	displayPrintQueue(printerJobs); 





	//Demos::simpleQueueDemo(); 

	//Demos::demoArrayBasedQueue(); 


	/*Let's APPLY a queue for some "neat" purpose*/


}

