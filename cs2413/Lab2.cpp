// --------------------------------------------------------------------------------
// AUTHOR: Avery Hewett
// FILENAME: Lab1.cpp
// SPECIFICATION: Create a menu driven progrtam that performs tasks with linked lists
// FOR: CS 2413 Data Structure Section 504
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct node *insert_beg(struct node* aStart, int num);

struct node {
	int data;
	struct node *next;
  struct node *prev;
};

struct node *start;

// --------------------------------------------------------------------------------
// NAME: display
// INPUT Param.: node
// OUTPUT Param.: linked list
// PURPOSE: display the linked list
// Is part of our example code that was provided
struct node *display(struct node *aStart) {
	struct node *ptr;                           // Auxiliar Pointer
	ptr = aStart;                               // Staert pointing to the Begining.
	cout << "\nLinked List:";
  while(ptr != NULL)
		{
			cout << " " << ptr->data;			  // prints the tab  then the value
			ptr = ptr -> next;                       //  THE pOINTER To the next node
		}
  cout << ".\n" << endl;
	return aStart;
}

// --------------------------------------------------------------------------------
// NAME: insert_beg
// INPUT Param.: node, int
// OUTPUT Param.: node
// PURPOSE: add data to the linked list
// Is part of our example code that was provided
struct node *insert_beg(struct node* aStart, int num) {
   //allocate memory for New node
   struct node* new_node = new node;

   //assign data to new node
   new_node->data = num;

   //new node is head and previous is null, since we are adding at the front
   new_node->next = (aStart);
   new_node->prev = NULL;

   //previous of head is new node
   if ((aStart) != NULL)
   (aStart)->prev = new_node;

   //head points to new node
   (aStart) = new_node;
   return aStart;
}

// --------------------------------------------------------------------------------
// NAME: rev
// INPUT Param.: aStart linked list
// OUTPUT Param.: void
// PURPOSE: Reverse the linked list
void rev(struct node* aStart){
  struct node *lside = aStart;					// Left side of the compared two in the list
  struct node *rside = aStart;
  int temp;
  while ( rside->next != NULL ){
    rside = rside->next;
  }
  temp = lside->data;
  lside->data = rside->data;
  rside->data = temp;
  lside = lside->next;
  rside = rside->prev;
  temp = lside->data;
  lside->data = rside->data;
  rside->data = temp;
}

// --------------------------------------------------------------------------------
// NAME: main
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: Make linked list and print menu for choices
int main(void) {
  int arrrrrr [5];
  cout << "Enter the 5 numbers into the array separated by spaces: ";
  cin >> arrrrrr[0] >> arrrrrr[1] >> arrrrrr[2] >> arrrrrr[3] >> arrrrrr[4];
  start = insert_beg(start, arrrrrr[4]); 		// inserting into list
  start = insert_beg(start, arrrrrr[3]);
  start = insert_beg(start, arrrrrr[2]);
  start = insert_beg(start, arrrrrr[1]);
  start = insert_beg(start, arrrrrr[0]);
	int i = 0;
	for ( ; ; ) {
		if (i == 3){
			break;
		}
		cout << "1: Print linked list generated\n2: Reverse linked list\n3: Close program\nPlease enter your choice: ";
		cin >> i;
	  switch(i) {
			case 1 :
				display(start);
				break;
			case 2 :
        rev(start);
        cout << "\n";
				break;
			case 3 :
				break;
			default :
				break;
		}
	}
  return 0;
}
