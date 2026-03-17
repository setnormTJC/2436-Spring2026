#include<string> 
#include <vector>

struct Node
{
	//vars:
	std::string data;
	Node* pNext = nullptr;

	//funcs:
	Node() = default;
	Node(std::string data, Node* pNext)
		:
		data(data), pNext(pNext)
	{

	}
};

class LinkedList
{
private:
	//int m_a; //member_a  ("Hungarian Notation)

	Node* pHead = nullptr;

	Node* pTail; //let's be SPACE HOGS and just ask for "lots" of space - and we'll be able to implement a more time-efficient
	//PUSH_BACk method (because QUEUES insert at rear and we want SPEED!) 

public:
	LinkedList() = delete;
	/*
	* @param dataInFrontNode -> this is the data that is INITIALLY in the front (AKA: head) node
	*/
	LinkedList(std::string dataInFrontNode);

	void pushFront(std::string newData);

	/*This is having time complexity O(1)*/
	void pushBack(std::string newData);

	//void popBack(); 

	/*This algorithm has complexity O(1) -> constant time complexity! Hooray!*/
	void popFront();

	void print();

};