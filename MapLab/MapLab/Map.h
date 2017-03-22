#pragma once
#include <string>
#include <stack>
#include <queue>
#include "Location.h"
#include <unordered_map>
using namespace std;

class Map
{
private:
	int x = 0;
	int y = 0;
public:
	Location *currentLocation = nullptr;
	Map(string startingLocationName);
	~Map();

	stack <Location*> Path;
	stack <Location*> PathCopy;
	queue <Location*> Destination;
	queue <Location*> DestinationCopy;

	void setPathCopy();
	void setDestinationCopy();
	void yMinusOne();
	void yPlusOne();
	void xMinusOne();
	void xPlusOne();

	Location * CoordinateCheck;
	unordered_map <string, Location*>::iterator it;
	unordered_map <string, Location*> Coordinates;
	//Location *CoordinateCheck(int _x, int _y);
	string getCoordinates();
	

};

