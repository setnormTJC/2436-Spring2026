#include<algorithm>
#include<iostream> 
#include <vector>

void demoLameExample()
{
	std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	/*put evens on "one side" and odds on the "other" side*/
	auto partitionLoc = std::partition(nums.begin(), nums.end(),
		[](const int a)
		{
			return a % 2 == 0;
		});
	/*Ignore the return value, if desired*/
	//for (const int num : nums)
	//	std::cout << num << " ";
	//std::cout << "\n\n\n\n";

	/*running up until only the partition*/
	for (auto it = nums.begin(); it != partitionLoc; ++it)
		std::cout << *it << " ";
	std::cout << "\n\n\n\n";
}

void demoUsefulCase()
{
	struct TestCase {
		std::string name;
		bool passed;
	};

	/*a more USEFUL example of partitioning -> FILTERING data!*/
	std::vector<TestCase> testCases = { {"Test1", true}, {"Test2", false}, {"Test3", true}, {"Test4", false} };

	/* Move all failed test cases to the end, keeping passed cases at the front */
	auto failStart = std::partition(testCases.begin(), testCases.end(),
		[](const TestCase& t) { return t.passed; });

	std::cout << "Passed tests:\n";
	for (auto it = testCases.begin(); it != failStart; ++it)
		std::cout << it->name << "\n";

	std::cout << "\nFailed tests:\n";
	for (auto it = failStart; it != testCases.end(); ++it)
		std::cout << it->name << "\n";
}

void demoAnotherUsefulCase()
{
	/*Yet another interesting/useful case: */
	struct Task {
		std::string description;
		bool isUrgent;
	};

	std::vector<Task> tasks = {
		{"Check email", false},
		{"Fix critical bug", true},
		{"Update documentation", false},
		{"Handle customer complaint", true}
	};

	/* Move urgent tasks to the front */
	std::partition(tasks.begin(), tasks.end(),



		[](const Task& t) { return t.isUrgent; });

	std::cout << "Reordered tasks:\n";
	for (const auto& task : tasks)
		std::cout << task.description << "\n";
}

int main()
{

	//demoLameExample(); 

	demoAnotherUsefulCase();


}
