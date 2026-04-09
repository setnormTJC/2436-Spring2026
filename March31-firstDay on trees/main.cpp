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
	//demoTreeTraversalAlgos(); 
	
	std::string rootValue = "Progenitor";
	NAryTree inheritanceTree(rootValue);
	SuperNode* pRoot = inheritanceTree.root(); 

	int desiredNumberOfChildren = 3; 
	for (int i = 0; i < desiredNumberOfChildren; ++i)
	{
		std::string childName = "child " + std::to_string(i); 
		inheritanceTree.addNode(childName, rootValue);
	}

	int a = 123; 


	//int desiredNumberOfGrandChildren_fromFirstChild = 5; 
	//for (int i = 0; i < desiredNumberOfGrandChildren_fromFirstChild; ++i)
	//{
	//	std::string 
	//}

	//BinarySearchTree bst;
}

