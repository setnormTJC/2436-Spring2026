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
	
	//demoNAryTree(); 

	//demoKevinBaconTree(); 


	//insert 8, 6, 7, 5, 3, 0, 9 into BST

	std::vector<std::string> jennysNumber =
	{
		"8",
		"6",
		"7",
		"5",
		"3",
		"0",
		"9"
	};

	BinarySearchTree bst(jennysNumber[0]); //"8" is stored in the root node

	Node* pRoot = bst.root(); 

	for (int i = 1; i < jennysNumber.size(); ++i) //note that we start at i = 1! (not 0)
	{
		bst.addNodeToBST(jennysNumber[i], pRoot);
	}

	//std::string targetNotInTree = "fdkskjdskj"; //force BF traversal of entire tree
	
	//bst.breadthFirstSearch(targetNotInTree);

	//int operationCount = 0; 
	//auto pTarget = bst.findInBST(targetNotInTree, pRoot, operationCount);

	//std::cout << "Number of operations for search in BST: " << operationCount << "\n";



	bst.depthFirstTraverse(pRoot); 

}

