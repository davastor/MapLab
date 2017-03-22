#pragma once
#include <string>
#include <unordered_map>

using namespace std;
class Location
{
private:
	string _name;


public:
	Location(string name);
	~Location();

	Location *North = nullptr;
	Location *South = nullptr;
	Location *West = nullptr;
	Location *East = nullptr;

	string GetLocationName();


};

