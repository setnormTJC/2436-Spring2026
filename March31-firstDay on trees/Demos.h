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