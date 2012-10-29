#include "Starbucks.h"
#include "Node.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <vector>

class ordwayjmStarbucks: public Starbucks
{
   public:
	 ordwayjmStarbucks(void);
	 ~ordwayjmStarbucks(void);
	 void build(Entry* c, int n);
	 Entry* getNearest(double x, double y);
	 void printInOrder(Node* r);

	 int size;
	 Node* root;
	 vector<Entry*> starbucks;
};