//Name: 	Avery Hewett
//Group:	Eric Johnson
//Section:	Lab 504/Lecture 004
//Problem:	Lab 11 
//Date:		4/23/2020
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct QNode{
	char key[100];
	struct QNode *next;
};

struct Queue{
	struct QNode *head, *tail;
};

struct QNode* newNode(char k[]){
	struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
	strcpy(temp->key, k);
	temp->next = NULL;
	return temp;
}

struct Queue *createQueue(){
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	q->head = q->tail = NULL;
	return q;
}

void enQueue(struct Queue *q, char k[]){
	struct QNode *temp = newNode(k);

	if (q->tail == NULL){
	q->head = q->tail = temp;
	return;
	}
	q->tail->next = temp;
	q->tail = temp;
}

struct QNode *deQueue(struct Queue *q){
	if (q->head == NULL)
	return NULL;

	struct QNode *temp = q->head;
	q->head = q->head->next;

	if (q->head == NULL)
		q->tail = NULL;
		return temp;
}

void printMenu(){
	printf("\n\n\n0. Call a customer\n");
	printf("1. Add a customer\n");
	printf("2. Quit\n");
	printf("Please input your command (0-2): ");
}

int main(){
	struct Queue *q = createQueue();
  
	while(1){
		printMenu();
		int option;
		scanf("%d", &option);
		if (option == 0){
			struct QNode *n = deQueue(q);
			if (n == NULL){
				printf("\n\nNo customer in line to call.");
			}else{
				printf("\n\nCalling %s", n->key);
			}
		}else if (option == 1){
			char name[100];
			printf("\n\nEnter a name: ");
			scanf("%s", name);
			enQueue(q, name);
		}else if (option == 2){
			break;
		}else{
			printf("Please choose from given menu.\n");
		}
	}
	return 0;
}