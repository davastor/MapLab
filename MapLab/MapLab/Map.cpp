#include "Map.h"



Map::Map(string startingLocationName)
{
	currentLocation = new Location(startingLocationName);
	Path.push(currentLocation);
	Destination.push(currentLocation);
	Coordinates.insert(make_pair("0, 0", currentLocation));
}


Map::~Map()
{
}

/*Location * Map::CoordinateCheck(int _x, int _y)
{
	string hash = "(" + to_string(x) + ", " + to_string(y) + ")";
	//return Coordinates[hash];
}*/

string Map::getCoordinates()
{
	string str;
	str = to_string(x) + ", " + to_string(y);

	return str;
}

void Map::setPathCopy()
{
	PathCopy = Path;
}

void Map::setDestinationCopy()
{
	DestinationCopy = Destination;
}

void Map::yMinusOne()
{
	y -= 1;
}

void Map::yPlusOne()
{
	y += 1;
}

void Map::xMinusOne()
{
	x -= 1;
}

void Map::xPlusOne()
{
	x += 1;
}
