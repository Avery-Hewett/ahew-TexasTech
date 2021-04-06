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

void deldupe(struct node **aStart);
void del(node *before_del);

struct node {
	int data;
	struct node *next;
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
struct node *insert_beg(struct node *aStart,int num) {
	struct node *new_node;                            // Declare a NEW Node
	new_node = (node *)malloc(sizeof( struct node));  // Allocate Memory
	new_node -> data = num;                           // Place DATA
	new_node -> next = aStart;                        // Link new Node to lis
	aStart = new_node;                                // update the address of the first node in the list
	return aStart;
}

// --------------------------------------------------------------------------------
// NAME: sortlow
// INPUT Param.: linked list
// OUTPUT Param.: sorted link list 0 -> 100
// PURPOSE: Sort data from lowest to highest using bubble sort
void sortlow(struct node **aStart) {
	struct node *temp = *aStart;
  *aStart = nullptr;

  while (temp) {
    struct node **lside = &temp;					// Left side of the compared two in the list
    struct node **rside = &temp->next;		// Right side of the compared two in the list
    bool isSwapped = false;        				// If function is swapped so it can adjust propperly to next  in the list

    while (*rside) {
	    if ((*rside)->data < (*lside)->data) { // swap
	      swap(*lside, *rside);
	      swap((*lside)->next, (*rside)->next);
	      lside = &(*lside)->next;
	      isSwapped = true;
	    } else {   // no swap
	    	lside = rside;
	      rside = &(*rside)->next;
	    }
    }
    *rside = *aStart;
    if (isSwapped) {
      *aStart = *lside;
      *lside = nullptr;
    } else {
      *aStart = temp;
      break;
    }
	}
}

// --------------------------------------------------------------------------------
// NAME: sorthigh
// INPUT Param.: linked list
// OUTPUT Param.: sorted link list 100 -> 0
// PURPOSE: Sort data from highest to lowest using bubble sort
void sorthigh(struct node **aStart) {
	struct node *temp = *aStart;
  *aStart = nullptr;

  while (temp) {
    struct node **lside = &temp;					// Left side of the compared two in the list
    struct node **rside = &temp->next;		// Right side of the compared two in the list
    bool isSwapped = false;								// If function is swapped so it can adjust propperly to next  in the list

    while (*rside) {
	    if ((*rside)->data > (*lside)->data) { // swap
	      swap(*lside, *rside);
	      swap((*lside)->next, (*rside)->next);
	      lside = &(*lside)->next;
	      isSwapped = true;
	    } else {   // no swap
	    	lside = rside;
	      rside = &(*rside)->next;
	    }
    }
    *rside = *aStart;
    if (isSwapped) {
      *aStart = *lside;
      *lside = nullptr;
    } else {
      *aStart = temp;
      break;
    }
	}
}

// --------------------------------------------------------------------------------
// NAME: sort
// INPUT Param.: Linked list
// OUTPUT Param.: None
// PURPOSE: The menu for sorting low>high or high>low and calls the correct funtion
struct node *sort(struct node *aStart) {
	struct node *ptr;                           // Auxiliar Pointer
	ptr = aStart;                               // Staert pointing to the Begining.
	int i = 0;
	for ( ; ; ) {
		if (i == 1 || i == 2 || i == 3){
			break;
		}
		cout << "\n1: Lowest to Highest\n2: Highest to Lowest\n3: Go to main menu\nPlease enter your choice: ";
		cin >> i;
	  switch(i) {
			case 1 :
				sortlow(&start);
				display(start);
				break;
			case 2 :
				sorthigh(&start);
				display(start);
				break;
			case 3 :
				break;
			default:
				break;
		}
	}
	return 0;
}

// --------------------------------------------------------------------------------
// NAME: del
// INPUT Param.: Linked list
// OUTPUT Param.: None
// PURPOSE: delete the one to the right of passed part of the list if it is a duplicate
void del(node *before_del) {
    node* temp;			// Temp placing for repairing list
    temp = before_del->next;
    before_del->next = temp->next;
    delete temp;
}

// --------------------------------------------------------------------------------
// NAME: deldupe
// INPUT Param.: Linked list
// OUTPUT Param.: None
// PURPOSE: Check if duplicates, print if any, ask to delete, if yes, call del
void deldupe(struct node *aStart) {
	struct node *right; 			// Right compared in list
	struct node *left;				// Left compared in list
	int count;								// Counts if there's a duplicate
	left = aStart;
	right = left->next;
	cout << "\n";
  while(right != NULL) {
		if (right->data == left->data){
			cout << left->data << " ";
			count++;
			//del(left);
			//right = left->next;
		}
		left = right;
		right = right->next;
	}
	if (count > 0){
		int i;
		cout << "\nWould you like to delete the duplicates (1: Yes/2: No): ";
		cin >> i;
		if (i == 1){
			left = aStart;
			right = left->next;

		  while(right != NULL) {
				if (right->data == left->data){
					//cout << left->data << " ";
					del(left);
					right = left->next;
				} else {
					left = right;
					right = right->next;
				}
			}
		}
	} else {
		cout << "\nThere are no duplicates.";
	}
	cout << "\n";
}

// --------------------------------------------------------------------------------
// NAME: main
// INPUT Param.: none
// OUTPUT Param.: menu choices
// PURPOSE: make a linked list & display menu and call tasks 1-4
int main(void) {
	int random;								// random variable
	srand(time(NULL));
	for (int j = 0; j < 20; j++) {
		random = rand() % 100;
		start = insert_beg(start, random); 		// inserting into list
	}
	int i = 0;
	for ( ; ; ) {
		if (i == 4){
			break;
		}
		cout << "1: Print linked list generated\n2: Sort the linked list\n3: Check if list has duplicates\n4: Close program\nPlease enter your choice: ";
		cin >> i;
	  switch(i) {
			case 1 :
				display(start);
				break;
			case 2 :
				sort(start);
				break;
			case 3 :
				sortlow(&start);
				deldupe(start);
				break;
			case 4 :
				break;
			default :
				break;
		}
	}
  return 0;
}
