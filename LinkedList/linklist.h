//Andreas Koudounis 40089191

#include "node.h"
#include <iostream>
#include <string>
 
class LinkedList
{
friend ostream& operator<<( ostream& out, LinkedList& list);
friend istream& operator>>(istream& in, LinkedList& list);
friend LinkedList operator+(const LinkedList& list1, const LinkedList& list2);
friend LinkedList operator-(const LinkedList& list1, const LinkedList& list2);
friend bool operator==(const LinkedList& list1, const LinkedList& list2);

private:
Node *head;
Node *tail;
int count;

public:
LinkedList();
~LinkedList();
void insert(char * val);
bool remove(char* val);
bool search(char* val);
int size();

const LinkedList& operator=(const LinkedList& otherList);
};

