#pragma once //only include this header file once ("guards" against redefinition errors)

#include<memory>
#include <string>

struct Node
{
	std::string data; 
	/*Don't!*/
	Node* pNext; //What's my data type, brother? 

	//the BETTER way!
	//std::unique_ptr<Node> pNext; 
};

class LinkedList
{
public: 

};

