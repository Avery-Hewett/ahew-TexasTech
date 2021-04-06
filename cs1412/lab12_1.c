#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int getseries(Stack *s)  {
  int n;
  printf("Input a series integers (ended with 0): ");
  while(1){
    scanf("%d",&n);
    if (n == 0){
        break;
    }
    else  {
      push( s , n );
    }
  }
}

int main() {
  Stack s;
  int n;
  s = create();
  getseries( &s );
  printf("\nPrinting number from stack: ");
  pop( &s );
  return 0;
}

typedef struct node{
  int n;
  struct node *next;
} Node, *temp,  *top;

struct stackHead{
  Node *head;
};

Stack create(void)  {
  Stack s;
  s = malloc(sizeof( struct stackHead) );
  (*s).head = NULL;
}

void push(Stack * s, int n )  {
  Node *temp;
  temp = malloc(sizeof(Node));
  temp->n = n;
  if ( (*s)->head == NULL ){
    temp->next =NULL;
    (*s)->head = temp;
    return;
  }
  temp->next = (*s)->head;
  (*s)->head = temp;
}

void pop(Stack * s){
  Node * temp = (*s)->head;
  while ( temp != NULL )  {
    printf("%d ", temp->n);
    temp = temp->next;
  }
}