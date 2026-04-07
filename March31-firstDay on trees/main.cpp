// March31-firstDay on trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include"Demos.h"
#include"Tree.h"


void doSomething()
{
	std::cout << "We are in this function: " << __FUNCTION__ << "\n";

	int a = 123; 
}


int main()
{
	//demoSimpleBinaryTree(); 

	BinaryTree binaryTree("Root");

	Node* pRoot = binaryTree.root(); 

	//level 1: 
	binaryTree.addNode("L"); //as in "left" child of root
	binaryTree.addNode("R"); //as in "right" child of root

	//Node* pDarthsParent = binaryTree.pRoot->pLeft->pLeft->pRight //the DUMB way

	//level 2:
	binaryTree.addNode("LL"); //as in "left, left" grandchild of root

	binaryTree.addNode("LR");

	binaryTree.addNode("RL");

	binaryTree.addNode("RR");


	binaryTree.depthFirstTraverse(pRoot);

	std::string target = "asfdasf";

	//Node* pTarget = binaryTree.breadthFirstSearch(target); 



	//BinarySearchTree bst;
}

