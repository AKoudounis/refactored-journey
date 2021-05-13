//Andreas Koudounis 40089191

#include "linklist.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, LinkedList& list)
{
    Node *current = list.head;

    while(current != NULL)
    {
      out << current->element << " ";
      current = current->next;
    }

    return out;
}


istream& operator>>(istream& in, LinkedList& list)
{
    char *t = new char;
    in >> t;

    list.insert(t);
    return in;
}


LinkedList operator+(const LinkedList& list1, const LinkedList& list2)
{
    LinkedList newList = list1;

    Node *current = list2.head;
    while(current != NULL)
    {
      newList.insert(current->element);
      current = current->next;
    }

    return newList;
    }


LinkedList operator-(const LinkedList& list1, const LinkedList& list2)
{
        LinkedList newList = list1;

    Node *current = list2.head;
    while(current != NULL)
    {
      newList.remove(current->element);
      current = current->next;
    }

    return newList;
}


bool operator==(const LinkedList& list1, const LinkedList& list2)
{
    if(list1.count != list2.count)
      return false;

    Node *t1 = list1.head;
    Node *t2 = list2.head;

    while(t1 != NULL && t2 != NULL)
    {
      if(strcmp(t1->element, t2->element) != 0)
       return false;

      t1 = t1->next;
      t2 = t2->next;
    }

    return true;
}


LinkedList::LinkedList()
{
    head = tail = NULL;
    count = 0;
}


LinkedList::~LinkedList()
{
    Node *t;

    while(head != NULL)
    {
      t = head;
      head = head->next;
      count--;
      delete t;
    }

    tail = NULL;
    cout << "Linkedlist object deleted successfully" << endl;
}


void LinkedList::insert(char * val)
{
    Node *newNode = new Node;
    newNode->element = val;
    newNode->next = NULL;

    if(head == NULL)
    {
      head = newNode;
      tail = newNode;
      count++;
    }
    else if(strcmp(head->element, val) > 0)
    {
      newNode->next = head;
      head = newNode;
      count++;
    }
    else if(strcmp(tail->element, val) < 0)
    {
      tail->next = newNode;
      tail = newNode;
      count++;
    }

    else
    {
      Node *current = head;
      Node *prev = NULL;

      while(current != NULL && strcmp(current->element, val) < 0)
      {
       prev = current;
       current = current->next;
      }

      if(strcmp(current->element, val) == 0)
      {
       cout << val << " is already in the list." << endl;
      }
      else
      {
       prev->next = newNode;
       newNode->next = current;
       count++;
      }
    }
}


bool LinkedList::remove(char * val)
{
    if(head == NULL)
      return false;

Node *current = head;

if( strcmp(head->element, val) == 0)
{
      head = head->next;
      delete current;
      count--;
      return true;
}

Node *prev = NULL;
    while(current != NULL && strcmp(current->element, val) != 0)
    {
      prev = current;
      current = current->next;
    }

if(current != NULL)
{
      if(prev->next == tail)
       tail = prev;

      prev->next = current->next;
      delete current;
      count--;
      return true;
}

return false;
}


bool LinkedList::search(char * val)
{
    if(head == NULL)
      return false;

Node *current = NULL;
    while(current != NULL)
    {
      if(strcmp(current->element, val) != 0)
       return true;

      current = current->next;
    }

return false;
}


int LinkedList::size()
{
return count;
}


const LinkedList& LinkedList::operator=(const LinkedList& otherList)
{
    delete this;
    count = 0;

LinkedList list;

Node *current = otherList.head;
    while(current != NULL)
      list.insert(current->element);

    return *this;
}


