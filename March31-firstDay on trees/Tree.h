#pragma once
#include<iostream> 
#include <string>
#include <vector>


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





/*A "SuperNode" is a node with potentially-unlimited numbers of children*/
class SuperNode
{
	std::string data; //tic tac toe board 
	std::vector<SuperNode*> pChildren; 

public: 
	SuperNode() = delete; 
	/*Note that this constructor leaves `pChildren` empty*/
	SuperNode(const std::string& data);

	friend class NAryTree;//give access to the privates
};


class NAryTree
{
	SuperNode* pRoot; 


public: 
	NAryTree() = delete; 
	NAryTree(const std::string& valueInRoot);

	SuperNode* root() const; 

	/*A sort of "edge/special case" to consider 
	- what if more than one instance of `parentValue` is in the tree??*/
	void addNode(const std::string& newValue, const std::string& parentValue); //how do it do what it s'posed ta do? 

	/*@param wasFound -> NOTE the passing by non-const reference!*/
	SuperNode* find(const std::string& target, SuperNode* pParent) const;

	/*AKA: is "childless"*/
	bool isLeaf(SuperNode* pValue) const;
};

