#pragma once
#include <string>
#include "Location.h"
using namespace std;

class Map
{
private:


public:
	Location *_currentLocation = nullptr;
	Map(string startingLocationName);
	~Map();

	

};

