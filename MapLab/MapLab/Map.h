#pragma once
#include <string>
#include <stack>
#include <queue>
#include "Location.h"
using namespace std;

class Map
{
private:


public:
	Location *currentLocation = nullptr;
	Map(string startingLocationName);
	~Map();

	stack <Location*> Path;
	queue <Location*> Destination;

	

};

