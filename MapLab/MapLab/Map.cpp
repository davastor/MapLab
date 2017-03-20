#include "Map.h"



Map::Map(string startingLocationName)
{
	currentLocation = new Location(startingLocationName);
	Path.push(currentLocation);
	Destination.push(currentLocation);
	Coordinates.emplace(0, 0, "Home");
}


Map::~Map()
{
}

string Map::getCoordinates()
{
	string str;
	str = to_string(x) + ", " + to_string(y);
	return string();
}

void Map::yMinusOne()
{
	y -= 1;
}
