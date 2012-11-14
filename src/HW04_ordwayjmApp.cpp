#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "ordwayjmStarbucks.h"
#include "Census.h"

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04_ordwayjmApp : public AppBasic {
  public:
	void prepareSettings(Settings* settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	
	void readStarbucks(string path);
	Census* readCensus(string path, int size);

	ordwayjmStarbucks starbucks;
	Entry* locations;
	Census* census2000;
	Census* census2010;
	int size;
private:
	static const int appWidth=555;
	static const int appHeight=352;
	
	gl::Texture map;

};

void HW04_ordwayjmApp::prepareSettings(Settings* settings)
{
	(*settings).setWindowSize(appWidth,appHeight);
	(*settings).setResizable(false);
}

void HW04_ordwayjmApp::setup()
{
	map = gl::Texture(loadImage("../resources/usa-map.jpg"));
	
	readStarbucks("../resources/Starbucks_2006.csv");
	starbucks.build(locations, size);

	census2000 = readCensus("../resources/Census_2000.csv", 206676);
	census2010 = readCensus("../resources/Census_2010.csv", 216331);
	console() << census2000[0].population << endl;
}

void HW04_ordwayjmApp::mouseDown( MouseEvent event )
{
}

void HW04_ordwayjmApp::update()
{

}

void HW04_ordwayjmApp::draw()
{
	gl::draw(map);
	
	// draw points on map. they don't seem to want to line up correctly...
	for(int i = 0; i < 7656; i++)
	{
		gl::color(Color8u(0, 89, 45));
		gl::drawSolidCircle(Vec2f(locations[i].x*getWindowSize().x+75,(1-locations[i].y)*getWindowSize().y),1);
	}
	gl::color(Color8u(255,255,255));
}

void HW04_ordwayjmApp::readStarbucks(string path)
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
	in.close();
}

Census* HW04_ordwayjmApp::readCensus(string path, int size)
{
	ifstream in(path);
	Census* temp = new Census[size];

	int trash;
	int population;
	int x;
	int y;
	string line;
	
	int i = 0;
	while(!in.eof()){
		getline(in, line, ',');
		getline(in, line, ',');
		getline(in, line, ',');
		getline(in, line, ',');
		in >> population;
		in.get();
		in >> x;
		in.get();
		in >> y;
		in.get();
		temp[i].population = population;
		temp[i].x = x;
		temp[i].y = y;
		i++;
	}
	in.close();
	return temp;
}

CINDER_APP_BASIC( HW04_ordwayjmApp, RendererGl )
