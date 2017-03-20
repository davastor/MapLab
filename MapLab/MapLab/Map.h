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
	int x;
	int y;

public:
	Location *currentLocation = nullptr;
	Map(string startingLocationName);
	~Map();

	stack <Location*> Path;
	queue <Location*> Destination;
	unordered_map <string, Location*> Coordinates;
	string getCoordinates();
	void yMinusOne();
	

};

