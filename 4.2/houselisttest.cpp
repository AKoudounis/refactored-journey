#include "houselist.h"

using namespace std;

int main()
{
	HouseList hl;
	int len = 0;
	char ch;

	do
	{
		hl.addHouse();
		
		cout << "\n Would you like to add one more house(Y / N): ";
		cin >> ch;

		if (ch == 'N' || ch == 'n')
			break;
	} while (1);

	hl.printHouses();
	
	hl.printCost();
	
	House* houserange = hl.returnRange(20000, 150000, len);
	
	hl.printRange(houserange, len);

	return 0;

}