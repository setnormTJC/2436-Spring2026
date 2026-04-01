#include "Tree.h"

Node::Node(const std::string& dataInRoot)
	: 
	data(dataInRoot)
{
}

Node* Node::get()
{
	return this; //double-check me, sir
}
