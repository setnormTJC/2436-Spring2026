#pragma once


#include"Tree.h"


#include<iostream> 

#ifdef _DEBUG //goofy lil workaround to "inactivate" this block of code
void demoSimpleBinaryTree()
{

	//a new (to me) macro/flag (metadata) thingy!
	std::cout << "We are in this function: " << __FUNCTION__ << "\n";

	Node* pRoot = new Node("Menu");

	Node* pFirstChild = new Node("Appetizers");

	Node* pSecondChild = new Node("Entrees");

	Node* pGrandchild = new Node("Steak");

	//pRoot->data = "NOT a menu"

	//pRoot->pLeft = pFirstChild; 
	//pRoot->pRight = pSecondChild; 

	//pRoot->pRight->pLeft = pGrandchild; 

	////std::cout << pRoot->pLeft->data << "\n";


	//std::cout << pSecondChild->pLeft->data << "\n";
	//std::cout << pRoot->pRight->pLeft->data << "\n";

}
#endif


/*Creates a "complete" tree with depth = 2, 
then traverses with BFT (breadth) and DFT (depth)*/
void demoTreeTraversalAlgos()
{
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

	std::string somethingNOTInTheTree = "asfdasf";

	Node* pTarget = binaryTree.breadthFirstSearch(somethingNOTInTheTree); 

	std::string somethingInTheTree = "RR";

	pTarget = binaryTree.breadthFirstSearch(somethingInTheTree); 
}

void demoKevinBaconTree()
{
	std::string theManTheMythTheLegend = "Kevin Bacon";
	NAryTree treeOfKevinBacon(theManTheMythTheLegend);
	//the "Bake" himself is the root

	SuperNode* pRoot = treeOfKevinBacon.root();

	//some folks with a Bacon number of 1: (one "degree of separation")
	treeOfKevinBacon.addNode("James McAvoy", theManTheMythTheLegend);//X-Men: Days of Future Past
	treeOfKevinBacon.addNode("Elisabeth Shue", theManTheMythTheLegend); //Hollow Man

	//Bacon number 2 folks
	treeOfKevinBacon.addNode("Ian McKellen", "James McAvoy"); //AKA: Gandalf from LotR
	treeOfKevinBacon.addNode("Ralph Macchio", "Elisabeth Shue"); //Karate Kid

	std::string targetNOTInTree = "ZEUS";
	auto pTarget = treeOfKevinBacon.find(targetNOTInTree, pRoot);

	std::string targetInTree = "Ralph Macchio";
	pTarget = treeOfKevinBacon.find(targetInTree, pRoot);

}

void demoNAryTree()
{
	std::string rootValue = "Progenitor";
	NAryTree familyTree(rootValue);
	SuperNode* pRoot = familyTree.root();

	int desiredNumberOfChildren = 3;
	for (int i = 0; i < desiredNumberOfChildren; ++i)
	{
		std::string childName = "child " + std::to_string(i);
		familyTree.addNode(childName, rootValue);
	}

	int desiredNumberOfGrandChildren_fromFirstChild = 5;
	std::string parentName = "child 0";
	for (int i = 0; i < desiredNumberOfGrandChildren_fromFirstChild; ++i)
	{
		std::string grandchildName = "grandchild + " + std::to_string(i);

		familyTree.addNode(grandchildName, parentName);
	}

	//now print the full tree (by searching for a value that is NOT in the tree):
	std::string target = "asdfasdfasdf";
	auto pTarget = familyTree.find(target, pRoot);

}