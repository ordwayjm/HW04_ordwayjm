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

Node* insert(Entry* e, Node* r) 
{
	if(r == NULL) return new Node(e);
	if(abs(e->x - r->c->x)<= 0.00001 && abs(e->y - r->c->y)<= 0.00001) return r;
	if(e->x < r->c->x) r->left = insert(e, r->left);
	else r->right = insert(e, r->right);
	return r;
}


void ordwayjmStarbucks::build(Entry* c, int n)
{
	c = shuffle(c, n);

	root = new Node(&c[0]); // create root node as first in shuffled array

	for(int i = 1; i < n; i++)
	{
		insert(&c[i], root);
	}
}

Entry* ordwayjmStarbucks::shuffle(Entry* c, int n)
{
   Entry temp;
   int r;
   int last;

   for (last = n; last > 1; last--)
   {
      r = rand() % last;
      temp = c[r];
      c[r] = c[last - 1];
      c[last - 1] = temp;
   }
   return c;
}

void ordwayjmStarbucks::printInOrder(Node* r) 
{
	if(r == NULL) return;
	if(r == root) console() << r->c->identifier << endl;
	printInOrder(r->left);
	console() << r->c->identifier << endl;
	printInOrder(r->right);
}

Entry* ordwayjmStarbucks::getNearest(double x, double y)
{
	Entry* start = new Entry();
	start->x = x;
	start->y = y;
	Entry* candidate = root->search(start, root);
	return candidate;
}