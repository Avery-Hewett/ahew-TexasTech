//Name: 	Avery Hewett
//Group:	Eric Johnson
//Section:	Lab 504/Lecture 004
//Problem:	Lab 7 
//Date:		3/9/2020
#include <stdio.h>

void moveDiscs(int n, char a, char c, char b){ 
    if (n == 1){ 
        printf("\n Move disk 1 from pole %c to pole %c", a, c); 
        return; 
    } 
    moveDiscs(n-1, a, b, c); 
    printf("\n Move disk %d from pole %c to pole %c", n, a, c); 
    moveDiscs(n-1, b, c, a);
}

int main(){
	int n;
	printf("Enter the number of discs you would like on pole: ");
	scanf("%d", &n);
	moveDiscs(n, 'A', 'C', 'B');
}