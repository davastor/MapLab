#include "Location.h"
#include <string>
using namespace std;


Location::Location(string name): _name(name)
{
}

Location::~Location()
{
}

string Location::GetLocationName()
{
	return _name;
}
