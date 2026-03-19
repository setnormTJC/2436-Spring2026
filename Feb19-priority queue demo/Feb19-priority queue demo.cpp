// Feb19-priority queue demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm>
#include <iostream>
#include <queue>

using namespace std; 

void demoLAMEExampleOfPQ()
{
	priority_queue<int> pq1;
	pq1.push(10);
	pq1.push(8675309);
	pq1.push(5);
	pq1.push(5595);


	cout << "Top of priority queue after enqueueing 10, 5, AND 5595:\n";
	cout << pq1.top() << endl;

	pq1.pop();

	cout << "NOW, after popping, queue contains as its HIGHEST PRIORITY item:\n";
	cout << pq1.top();
}

struct PrinterJob
{
	string filename;
	int pageCount;
	PrinterJob(string filename, int pageCount)
		:filename(filename), pageCount(pageCount)
	{
	};


	/*Compares by filename (alphabetizes)*/
	bool operator < (const PrinterJob& other) const
	{
		return (this->filename < other.filename);
	}
};


int main()
{
	srand(time(0));
	PrinterJob firstJob{ "birds.doc", 9};
	//(using random page count so no anticipated order)
	PrinterJob secondJob{ "silt.txt", 2};
	PrinterJob thirdJob{ "dictionary.doc", 7};


	vector<PrinterJob> jobs =
	{
		firstJob,
		secondJob,
		thirdJob
	};

	//std::sort(jobs.begin(), jobs.end()); 

	std::priority_queue<PrinterJob> printQueue;
	printQueue.push(firstJob);
	printQueue.push(secondJob);
	printQueue.push(thirdJob);1


}
