#include "Node.h"

Node::Node(Entry* c)
{
	left = right = NULL;
	this->c = c;
}


Node::~Node(void)
{
}

Entry* Node::search(Entry* key, Node* r)
{
	if(r == NULL) return NULL;
	if(key->x == r->c->x) return r->c;
	Entry* found;
	if(key->x <= r->c->x) {
		if(r->left == NULL)
		{
			found = r->c;
		}
		else found = search(key, r->left);
	}
	else 
	{
		if(r->right == NULL)
		{
			found = r->c;
		}
		else found = search(key, r->right);
	}
	return found;
}