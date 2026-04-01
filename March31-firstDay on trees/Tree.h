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
	Node() = delete; 
	Node(const std::string& dataInRoot); 

	/*returns node address (ex: for certain BinaryTree algos below)*/
	Node* get(); 

	/*@returns pLeft*/
	Node* left();
	/*@returns pRight*/
	Node* right(); 
};


class BinaryTree
{
	//what is the critical/vital pointer (Node*) in a tree? (what member variable should go here?)
public: 
	/*Adds preferentially to the left node, then the right (an arbitrary choice)*/
	virtual void addNode(const std::string& newData); //note the virtual modifier!


	/*Note that getting a particular pNode */
	void isLeaf(Node* pNode); 

	/*Credit to EJH for this terminology - see the image at the link below for an explanation of
	the meaning of "fork": 
	https://github.com/setnormTJC/2436-Spring2026/blob/master/March31-firstDay%20on%20trees/The%20fork%20proof.jpg
	*/
	void isFork(Node* pNode); 

	/*
	* @returns pRoot
	*/
	Node* root(); 
};

class BinarySearchTree : public BinaryTree //note the inheritance
{
	void addNode(const std::string& newData) override; //note the override modifier!
};