#pragma once
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

	/*
	* Uses BFS or DFS (pick your poison)
	@returns node address (ex: for certain BinaryTree algos below)
	*@param targetData -> note that if more than one instance of "targetData" is in tree, the "first" occurrence is returned
	*/
	Node* get(const std::string& targetData); 

	///*@returns pLeft*/
	//Node* left();
	///*@returns pRight*/
	//Node* right(); 

	friend class BinaryTree; //gives BinaryTree access to pLeft and pRight and data
};


class BinaryTree
{
	Node* pRoot; //this one is the KING (important)

	//what is the critical/vital pointer (Node*) in a tree? (what member variable should go here?)
public: 
	BinaryTree() = delete; 
	BinaryTree(const std::string dataInTheRoot);

	/*Adds preferentially to the left node, then the right (an arbitrary choice)*/
	virtual void addNode(const std::string& newData, Node* pParent); //note the virtual modifier!


	/*Note that getting a particular pNode */
	void isLeaf(Node* pNode); 

	/*Credit to EJH for this terminology - see the image at the link below for an explanation of
	the meaning of "fork": 
	https://github.com/setnormTJC/2436-Spring2026/blob/master/March31-firstDay%20on%20trees/The%20fork%20proof.jpg
	*/
	void isFork(Node* pNode); 


	//void BFS(); 

	//void DFS(); 

	/*
	* @returns pRoot (DOXYGEN)
	*/
	Node* root(); 
};

class BinarySearchTree : public BinaryTree //note the inheritance
{
	void addNode(const std::string& newData, Node* pParent) override; //note the override modifier!
};

