//Name: 	Avery Hewett
//Group:	Eric Johnson
//Section:	Lab 504/Lecture 004
//Problem:	Lab 12 
//Date:		4/28/2020
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node{
	int data;
	struct node *link;
}*top,*top1,*temp;

void push(int num){
	if (top == NULL){
		top =(struct node *)malloc(1*sizeof(struct node));
		top->link = NULL;
		top->data = num;
	}else{
		temp =(struct node *)malloc(1*sizeof(struct node));
		temp->link = top;
		temp->data = num;
		top = temp;
	}
}

void display(){
	top1 = top;
	if (top1 == NULL){
		printf("None");
		return;
	}
	while (top1 != NULL){
		printf("%d ", top1->data);
		top1 = top1->link;
	}
}

int main(){
	int n;
	top = NULL;
	printf("\nInput a series of intergers (ended with 0): ");
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}else{
			push(n);
		}
	}
	display();
	return 0;   
}