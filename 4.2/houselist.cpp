#include "houselist.h"

using namespace std;

HouseList::HouseList()
{
	items = new House[LIST_SIZE];
	numItems = 0;
}

HouseList::~HouseList()
{
}

void HouseList::addHouse()
{
	int age;
	string type;
	int numberofrooms;
	double currentCost;

	if (numItems == LIST_SIZE)
		cout << "\n ERROR: Cannot add an additional house. House list is full.";

	else
	{
		cout << "\n Enter the age of house: ";
		cin >> age;
		cout << "\n Enter type of House (Attached / Semi-Detached / Detached): ";
		cin >> type;
		cout << "\n Enter number of Rooms: ";
		cin >> numberofrooms;
		cout << "\n Enter current Cost: $";
		cin >> currentCost;

		items[numItems].setAge(age);
		items[numItems].setType(type);
		items[numItems].setUnit(numberofrooms);
		items[numItems].setCurrentCost(currentCost);
		
		numItems++;
	}
}

void HouseList::printHouses()
{
	cout << "\n\n *************** All Info ***************\n";
	for (int c = 0; c < numItems; c++)
		items[c].showhouse();
}

void HouseList::printCost()
{
	cout << "\n\n *************** Prices ***************\n";

	for (int c = 0; c < numItems; c++)
		cout << items[c].getCurrentCost() << endl;
}

House* HouseList::returnRange(double startRange, double endRange, int& len)
{
	House* rangeHouse = new House[numItems];

	for (int c = 0; c < numItems; c++)
	{
		if (items[c].getCurrentCost() >= startRange && items[c].getCurrentCost() <= endRange)
			rangeHouse[len++] = items[c];
	}
	return rangeHouse;
}

void HouseList::printRange(House* rangeHouse, int len)
{
	cout << "\n\n ******** House Information Within Range ********\n";

	for (int c = 0; c < len; c++)
		
		rangeHouse[c].showhouse();
}