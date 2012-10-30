#include "Starbucks.h"

class Node
{
   public:
     Node(Entry* c);
	 ~Node(void);
	 Entry* search(Entry* key, Node* r);

	 Node* left;
	 Node* right;
	 Entry* c;
};