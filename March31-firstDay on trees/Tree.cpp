#include "Tree.h"
#include <iostream>
#include <queue>

Node::Node(const std::string& data)
	: 
	data(data)
{
}




BinaryTree::BinaryTree(const std::string dataInTheRoot)
{
	pRoot = new Node(dataInTheRoot);

	pRoot->pLeft = nullptr; 
	pRoot->pRight = nullptr; 

}

void BinaryTree::addNode(const std::string& newData)
{
	//std::cout << "\n\nInserting " << newData << "...\n";

	Node* pNew = new Node(newData); //make the new node

	std::queue<Node*> visitedNodes; //allows us to find an empty spot to insert

	visitedNodes.push(pRoot); 

	bool newDataWasAdded = false; 

	while (newDataWasAdded == false)
	{
		Node* pFront = visitedNodes.front(); 

		if (pFront->pLeft == nullptr) //the spot is empty
		{
			pFront->pLeft = pNew; 
			newDataWasAdded = true; 
		}

		else if (pFront->pRight == nullptr)
		{
			pFront->pRight = pNew; 
			newDataWasAdded = true; 
		}

		else //both left and right were full - add them to the queue
		{
			//std::cout << "Visiting " << pFront->data << " and adding its children to the queue.\n";
			visitedNodes.push(pFront->pLeft);
			visitedNodes.push(pFront->pRight);

			visitedNodes.pop(); 
		}

	}

}

void BinaryTree::addNode(const std::string& newData, Node* pParent)
{

}

void BinaryTree::depthFirstTraverse(Node* pParent) const
{
	if (pParent == nullptr) //base case
	{
		return;
	}

	//recursive case: 
	//go left, "visit", then go right
	depthFirstTraverse(pParent->pLeft);
	std::cout << pParent->data << "\n";
	depthFirstTraverse(pParent->pRight);
}



Node* BinaryTree::breadthFirstSearch(const std::string& target) const
{
	std::queue<Node*> visitedNodes;

	visitedNodes.push(pRoot);

	bool targetWasFound = false;
	Node* pTarget = nullptr; 

	while (!visitedNodes.empty() && !targetWasFound)
	{
		Node* pFront = visitedNodes.front();
		visitedNodes.pop(); 

		std::cout << pFront->data << "\n";

		if (pFront->data == target) //sort of a best case - target was right at the front
		{
			targetWasFound = true;
			pTarget = pFront; 
		}

		else //perhaps the left or right child contains the target...
		{
			if (pFront->pLeft != nullptr)
			{
				visitedNodes.push(pFront->pLeft);
			}

			if (pFront->pRight != nullptr)
			{
				visitedNodes.push(pFront->pRight);
			}
		}
	}

	return pTarget;
}

Node* BinaryTree::root()
{
	return pRoot;
}











void BinarySearchTree::addNode(const std::string& newData)
{

}