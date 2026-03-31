// March31-firstDay on trees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include"Tree.h"

int main()
{
	
	BinaryTreeNode* pRoot = new BinaryTreeNode("Menu");

	BinaryTreeNode* pFirstChild = new BinaryTreeNode("Appetizers");

	BinaryTreeNode* pSecondChild = new BinaryTreeNode("Entrees");

	BinaryTreeNode* pGrandchild = new BinaryTreeNode("Steak");

	//pRoot->data = "NOT a menu"

	pRoot->pLeft = pFirstChild; 
	pRoot->pRight = pSecondChild; 

	pRoot->pRight->pLeft = pGrandchild; 

	//std::cout << pRoot->pLeft->data << "\n";


	std::cout << pSecondChild->pLeft->data << "\n";
	std::cout << pRoot->pRight->pLeft->data << "\n";

}

