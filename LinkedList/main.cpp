//Andreas Koudounis 40089191

#include "linklist.h"

using namespace std;

int main()
{
    LinkedList L1, L2;

    cout << "Enter 5 values for list 1: " << endl;
    for (int i = 0; i < 5; i++)
        cin >> L1;

    cout << "\nEnter 5 values for list 2: " << endl;
    for (int i = 0; i < 5; i++)
    {
        char* str = new char;
        cin >> str ;
        L2.insert(str);
    }

 

    cout << "\nList1: " << L1 << endl;
    cout << "List2: " << L2 << endl;



    cout << endl;
    system("pause");
    return 0;
}