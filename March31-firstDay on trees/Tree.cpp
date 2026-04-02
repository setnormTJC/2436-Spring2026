#include "Tree.h"
#include <iostream>

Node::Node(const std::string& data)
	: 
	data(data)
{
}

Node* Node::get(const std::string& targetData)
{
	//call BFS or DFS until 1) found or 2) not in tree
	return nullptr; //temporary return value 
}


BinaryTree::BinaryTree(const std::string dataInTheRoot)
{
	pRoot = new Node(dataInTheRoot);

	pRoot->pLeft = nullptr; 
	pRoot->pRight = nullptr; 

}

void BinaryTree::addNode(const std::string& newData, Node* pParent)
{

	Node* newNode = new Node(newData);

	//add preferentially to the left, if left is OCCUPPIED, add to the right
	if (pParent->pLeft == nullptr)
	{
		pParent->pLeft = newNode; 
	}

	else if (pParent->pRight == nullptr) //right child does not yet exist
	{
		pParent->pRight = newNode; 
	}

	else //we're full up!
	{
		std::cout << "All full here - cannot add " << newData << "\n";
	}
}


Node* BinaryTree::root()
{
	return pRoot; //temporary return value
}











void BinarySearchTree::addNode(const std::string& newData, Node* pParent)
{

}