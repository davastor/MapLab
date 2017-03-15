#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

int main();

void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);
void PathHome(Map &map);


int main()
{
	Map map = Map("Home");

	int choice = -1;

	while (choice != 0)
	{
		system("cls");
		cout << "Choose an option" << endl;
		cout << "0) Exit" << endl;
		cout << "1) Get current location info" << endl;
		cout << "2) Go north" << endl;
		cout << "3) Go south" << endl;
		cout << "4) Go west" << endl;
		cout << "5) Go east" << endl;
		cout << "6) Path to home" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			break;
		case 1:
			system("cls");
			cout << "You are at: " << map.currentLocation->GetLocationName() << endl;
			break;
		case 2:
			GoNorth(map);
			break;
		case 3:
			GoSouth(map);
			break;
		case 4:
			GoWest(map);
			break;
		case 5:
			GoEast(map);
			break;
		case 6:
			PathHome(map);
			break;
		default:
			cout << "please enter a valid option" << endl;
		}

		system("pause");
	}



	system("pause");
	return 0;
}

void GoNorth(Map & map)
{
	system("cls");
	if (map.currentLocation->North == nullptr)
	{
		cout << "You haven't been here before.  Enter a Name: ";
		string newName;
		cin >> newName;
		map.currentLocation->North = new Location(newName);
		map.currentLocation->North->South = map.currentLocation;
		
	}
	map.currentLocation = map.currentLocation->North;
	cout << "You are now at " + map.currentLocation->GetLocationName() << endl;
	map.Path.push(map.currentLocation);
	map.Destination.push(map.currentLocation);
}

void GoSouth(Map & map)
{
	system("cls");
	if (map.currentLocation->South == nullptr)
	{
		cout << "You haven't been here before.  Enter a Name: ";
		string newName;
		cin >> newName;
		map.currentLocation->South = new Location(newName);
		map.currentLocation->South->North = map.currentLocation;

	}
	map.currentLocation = map.currentLocation->South;
	cout << "You are now at " + map.currentLocation->GetLocationName() << endl;
	map.Path.push(map.currentLocation);
	map.Destination.push(map.currentLocation);
}

void GoEast(Map & map)
{
	system("cls");
	if (map.currentLocation->East == nullptr)
	{
		cout << "You haven't been here before.  Enter a Name: ";
		string newName;
		cin >> newName;
		map.currentLocation->East = new Location(newName);
		map.currentLocation->East->West = map.currentLocation;
	}
	map.currentLocation = map.currentLocation->East;
	cout << "You are now at " + map.currentLocation->GetLocationName() << endl;
	map.Path.push(map.currentLocation);
	map.Destination.push(map.currentLocation);
}

void GoWest(Map & map)
{
	system("cls");
	if (map.currentLocation->West == nullptr)
	{
		cout << "You haven't been here before.  Enter a Name: ";
		string newName;
		cin >> newName;
		map.currentLocation->West = new Location(newName);
		map.currentLocation->West->East = map.currentLocation;

	}
	map.currentLocation = map.currentLocation->West;
	cout << "You are now at " + map.currentLocation->GetLocationName() << endl;
	map.Path.push(map.currentLocation);
	map.Destination.push(map.currentLocation);
}

void PathHome(Map & map)
{
	system("cls");
	while (map.currentLocation->GetLocationName() != "Home")
	{
		map.Path.pop();
		map.currentLocation = map.Path.top();
	}
	cout << "You are now at " << map.currentLocation->GetLocationName() << endl;
}

void ToDestination(Map& map) // finish
{
	system("cls");
	while (map.currentLocation->GetLocationName() != "Home")
	{
		map.Path.pop();
		map.currentLocation = map.Path.top();
	}
	cout << "You are now at " << map.currentLocation->GetLocationName() << endl;
}
