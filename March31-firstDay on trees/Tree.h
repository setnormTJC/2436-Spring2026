#pragma once
#include<iostream> 
#include <string>


/*"Node" means a binary tree node (has a left and right pointer) in this case*/
class Node
{
	std::string data; 

	Node* pLeft{};
	Node* pRight{};

public: 

	/*Constructor functions*/
	Node() = delete; //deleted default constructor
	Node(const std::string& dataInRoot); 


	friend class BinaryTree; //gives BinaryTree access to pLeft and pRight and data
};


class BinaryTree
{
	Node* pRoot; //this one is the KING (important)


public: 
	BinaryTree() = delete; 
	BinaryTree(const std::string dataInTheRoot);

	/*Adds preferentially to the left node, then the right (an arbitrary choice)*/
	virtual void addNode(const std::string& newData); //note the virtual modifier!
	
	/*A RECURSIVE version of adding new data to a binary tree*/
	void addNode(const std::string& newData, Node* pParent);

	/*AKA: print the data in all nodes of the tree*/
	void depthFirstTraverse(Node* pParent) const; 

	/*Note that getting a particular pNode */
	void isLeaf(Node* pNode); 

	/*Credit to EJH for this terminology - see the image at the link below for an explanation of
	the meaning of "fork": 
	https://github.com/setnormTJC/2436-Spring2026/blob/master/March31-firstDay%20on%20trees/The%20fork%20proof.jpg
	*/
	void isFork(Node* pNode); 


	/*Why return a pointer? Recall that for sequential and binary search on an ARRAY, 
	we generally return an index (-1 if not found) or a boolean (false, if not found)*/
	Node* breadthFirstSearch(const std::string& target) const; 

	//void DFS(); 

	/*
	* @returns pRoot (DOXYGEN)
	*/
	Node* root(); 
};

class BinarySearchTree : public BinaryTree //note the inheritance
{
public: 
	void addNode(const std::string& newData) override; //note the override modifier!
};

