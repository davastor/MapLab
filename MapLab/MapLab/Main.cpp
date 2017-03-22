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
void ToDestination(Map &map);

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
		cout << "6) Find path home" << endl;
		cout << "7) Find path to current location" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			break;
		case 1:
			system("cls");
			cout << "You are at: " << map.currentLocation->GetLocationName() + " (" + map.getCoordinates() + ")" << endl;
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
		case 7:
			ToDestination(map);
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
	map.yPlusOne();

	//map.Coordinates[map.getCoordinates()] 
	if (map.Coordinates.find(map.getCoordinates()) == map.Coordinates.end())
	{
		cout << "You haven't been here before.  Enter a Name: ";
		string newName;
		cin >> newName;
		map.currentLocation->North = new Location(newName);
		map.Coordinates.insert(make_pair(map.getCoordinates(), map.currentLocation->North));
		map.currentLocation->North->South = map.currentLocation;
		
	}

	map.it = map.Coordinates.find(map.getCoordinates());
	map.currentLocation = map.it->second;
	//map.currentLocation = map.currentLocation->North;
	cout << "You are now at " + map.currentLocation->GetLocationName() + " (" + map.getCoordinates() + ")" << endl;
	map.Path.push(map.currentLocation);
	map.Destination.push(map.currentLocation);
}

void GoSouth(Map & map)
{
	system("cls");
	map.yMinusOne();

	if (map.Coordinates.find(map.getCoordinates()) == map.Coordinates.end())
	{
	
		
		cout << "You haven't been here before.  Enter a Name: ";
		
		string newName;
		cin >> newName;
		map.currentLocation->South = new Location(newName);
		map.Coordinates.insert(make_pair(map.getCoordinates(), map.currentLocation->South));
		map.currentLocation->South->North = map.currentLocation;

	}
	map.it = map.Coordinates.find(map.getCoordinates());
	map.currentLocation = map.it->second;
	//map.currentLocation = map.currentLocation->South;
	cout << "You are now at " + map.currentLocation->GetLocationName() + " (" + map.getCoordinates() + ")" << endl;
	map.Path.push(map.currentLocation);
	map.Destination.push(map.currentLocation);
}

void GoEast(Map & map)
{
	system("cls");
	map.xPlusOne();

	if (map.Coordinates.find(map.getCoordinates()) == map.Coordinates.end())
	{
		cout << "You haven't been here before.  Enter a Name: ";
		string newName;
		cin >> newName;
		map.currentLocation->East = new Location(newName);
		map.Coordinates.insert(make_pair(map.getCoordinates(), map.currentLocation->East));
		map.currentLocation->East->West = map.currentLocation;
	}
	map.it = map.Coordinates.find(map.getCoordinates());
	map.currentLocation = map.it->second;
	//map.currentLocation = map.currentLocation->East;
	cout << "You are now at " + map.currentLocation->GetLocationName() + " (" + map.getCoordinates() + ")" << endl;
	map.Path.push(map.currentLocation);
	map.Destination.push(map.currentLocation);
}

void GoWest(Map & map)
{
	system("cls");
	map.xMinusOne();

	if (map.Coordinates.find(map.getCoordinates()) == map.Coordinates.end())
	{
		cout << "You haven't been here before.  Enter a Name: ";
		string newName;
		cin >> newName;
		map.currentLocation->West = new Location(newName);
		map.Coordinates.insert(make_pair(map.getCoordinates(), map.currentLocation->West));
		map.currentLocation->West->East = map.currentLocation;

	}
	map.it = map.Coordinates.find(map.getCoordinates());
	map.currentLocation = map.it->second;
	//map.currentLocation = map.currentLocation->West;
	cout << "You are now at " + map.currentLocation->GetLocationName()  + " (" + map.getCoordinates() + ")" << endl;
	map.Path.push(map.currentLocation);
	map.Destination.push(map.currentLocation);
}

void PathHome(Map & map)
{
	system("cls");

	if (map.currentLocation->GetLocationName() == "Home")
	{
		cout << "You are already home." << endl;
		
		do {map.Path.pop();} while (map.Path.empty() != false);
	}
	else
	{
		map.setPathCopy();
		cout << "Path to Home" << endl;
		int i = 1;
		while (map.PathCopy.top()->GetLocationName() != "Home")
		{
			map.PathCopy.pop();
			cout << i << ")" << map.PathCopy.top()->GetLocationName() << endl;
			i++;
		}
	}
}

void ToDestination(Map& map) 
{
	system("cls");
	int i = 1;

	map.setDestinationCopy();
	cout << "Path to Current Location" << endl;
	while (map.DestinationCopy.front()->GetLocationName() != map.currentLocation->GetLocationName())
	{
		
		cout << i << ") " << map.DestinationCopy.front()->GetLocationName() << endl;
		map.DestinationCopy.pop();
		i++;
	}
	cout << i << ") " << map.currentLocation->GetLocationName() << endl;;
}
