#include "ordwayjmStarbucks.h"
#include <fstream>;
#include <iostream>;

using namespace ci;
using namespace ci::app;
using namespace std;

ordwayjmStarbucks::ordwayjmStarbucks(void) 
{
}

ordwayjmStarbucks::~ordwayjmStarbucks(void)
{
}

Node* insert(Entry* e, Node* r) {
	if(r == NULL) return new Node(e);
	if(abs(e->x - r->c->x)<= 0.00001 && abs(e->y - r->c->y)<= 0.00001) return r;
	if(e->x < r->c->x) {
		r->left = insert(e, r->left);
	}
	else {
		r->right = insert(e, r->right);
	}
	return r;
}


void ordwayjmStarbucks::build(Entry* c, int n)
{
	// shuffle c first

	root = new Node(&c[n/2]); // create root node as median

	for(int i = 0; i < n; i++)
	{
		insert(&c[i], root);
	}
}

void ordwayjmStarbucks::printInOrder(Node* r) {
	if(r == NULL) return;
	printInOrder(r->left);
	console() << r->c->identifier << endl;
	printInOrder(r->right);
}

Entry* ordwayjmStarbucks::getNearest(double x, double y)
{
	return 0;
}