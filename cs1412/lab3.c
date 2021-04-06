//Name: 	Avery Hewett
//Group:	Sebastian Agulara, Oliver Farnun
//Section:	Lab 504/Lecture 004
//Problem:	Lab 3 
//Date:		2/11/2020

#include <stdio.h>

void q1(){
	int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, sum1, sum2, total, total2;
	printf("Enter the first single digit: ");
	scanf("%1d", &d);
	printf("Enter the first group of 5 digits: ");
	scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
	printf("Enter the second group of 5 digits: ");
	scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
	
	sum1 = d + i2 + i4 + j1 + j3 + j5;
	sum2 = i1 + i3 + i5 + j2 + j4;
	total = 3 * sum1 + sum2;
	total2 = 9 - ((total - 1) % 10);
	
	printf("Check digit: %d\n\n\n", total2);
}

void q2(){
	printf("Enter n: ");
	int n;
	scanf("%d", &n);
	int f;
	while (n>0){
		printf("%d", n%10);
		n = n/10;
	}
}

int main()
{
	q1(); //Part 1
	q2(); //Part 2
}
