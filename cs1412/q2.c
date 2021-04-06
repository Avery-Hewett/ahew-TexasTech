//Name: 	Avery Hewett
//Group:	Sebastian Agulara, Oliver Farnun
//Section:	Lab 504/Lecture 004
//Problem:	Lab 2 
//Date:		2/3/2020

#include <stdio.h>
void q2a(){
	printf("Enter date (MM/DD/YYYY): ");
    int mon, day, year;
	scanf("%d/%d/%d", &mon, &day, &year);
	printf("%04d",year);
	printf("%02d",mon);
	printf("%02d",day);
	printf("\n\n");	
}

int q2b(int m, int n){
	if(m==0){
		return 0;
	} else {
		printf("Important Message Needs to Repeated %d Times\n", n);
		m--;
		q2b(m, n);
	}
}

int main()
{
	q2a(); // Question 2 a
	printf("Enter M: ");
	int m;
	scanf("%d", &m);
	int n = m;
	q2b(m, n); // Question 2 b
	return 0;
}
