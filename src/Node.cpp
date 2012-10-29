#include "Node.h"

Node::Node(Entry* c)
{
	left = right = NULL;
	this->c = c;
}


Node::~Node(void)
{
}