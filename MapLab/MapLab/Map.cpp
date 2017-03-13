#include "Map.h"



Map::Map(string startingLocationName)
{
	_currentLocation = new Location(startingLocationName);
}


Map::~Map()
{
}
