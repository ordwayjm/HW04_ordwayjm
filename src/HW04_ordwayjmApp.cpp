#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ordwayjmStarbucks.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04_ordwayjmApp : public AppBasic {
  public:
    void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	void readCSV(string path);

	Entry* locations;
	int size;
};

void HW04_ordwayjmApp::setup()
{
	readCSV("Starbucks_2006.csv");
	ordwayjmStarbucks starbucks;
	starbucks.build(locations, size);
	starbucks.printInOrder(starbucks.root);
}

void HW04_ordwayjmApp::mouseDown( MouseEvent event )
{
}

void HW04_ordwayjmApp::update()
{
}

void HW04_ordwayjmApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

void HW04_ordwayjmApp::readCSV(string path)
{
	size = 7656;
	locations = new Entry[size];

	ifstream in(path);

	double x;
	double y;

	int i = 0;
	while(!in.eof()){
		getline(in, locations[i].identifier, ',');
		in.get();
		in >> x;
		in.get();
		in >> y;

		locations[i].x = x;
		locations[i].y = y;
		
		i++;
	}
}

CINDER_APP_BASIC( HW04_ordwayjmApp, RendererGl )
