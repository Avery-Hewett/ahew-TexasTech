#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
   int n;
   struct node *next;
} Node; 

struct stackHead {
   Node *head;
};

typedef stackHead *Stack;
 
Stack create(void)
{
  Stack s1;
 
  // allocate memory 
  s1 = malloc(sizeof(struct stackHead)); 
  (*s1).head = NULL; 
  return s1;
}

void push(Stack s2, int n)
{
   Node *temp; 
 
   // create a node to contain number n
   temp = malloc(sizeof(Node));
   (*temp).n = n;
   // temp becomes the head of the list
   (*temp).next = (s2->head);
   (*s2).head = temp; // question iv)
   temp = NULL; 
}