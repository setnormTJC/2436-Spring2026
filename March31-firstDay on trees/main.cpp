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

	BinaryTree binaryTree("Alice");


	Node* pRoot = binaryTree.root(); 

	binaryTree.addNode("Bob", pRoot);

	binaryTree.addNode("Carol", pRoot);


	//Node* pDarthsParent = binaryTree.pRoot->pLeft->pLeft->pRight //the DUMB way

	//binaryTree.addNode("Darth", pRoot);





	//BinarySearchTree bst;
}

