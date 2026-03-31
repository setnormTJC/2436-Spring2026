#pragma once
#include <string>


class BinaryTreeNode
{
public: 
	std::string data; 


	BinaryTreeNode* pLeft; 
	BinaryTreeNode* pRight;



	/*Constructor function*/

	BinaryTreeNode() = delete; 
	BinaryTreeNode(const std::string& dataInRoot); 
};