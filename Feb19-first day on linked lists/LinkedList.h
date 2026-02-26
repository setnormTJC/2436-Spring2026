#pragma once //only include this header file once ("guards" against redefinition errors)

#include<memory>
#include <string>

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
public: 
	LinkedList() = delete; 
	/*
	* @param dataInFrontNode -> this is the data that is INITIALLY in the front (AKA: head) node
	*/
	LinkedList(std::string dataInFrontNode);

	void pushFront(std::string newData);

	//void popBack(); 

	/*This algorithm has complexity O(1) -> constant time complexity! Hooray!*/
	void popFront(); 

	void print(); 

};

