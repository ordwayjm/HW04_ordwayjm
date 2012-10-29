#include "Starbucks.h"

class Node
{
   public:
     Node(Entry* c);
	 ~Node(void);

	 Node* left;
	 Node* right;
	 Entry* c;
};