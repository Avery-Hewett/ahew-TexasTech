//Name: 	Avery Hewett
//Group:	Eric Johnson
//Section:	Lab 504/Lecture 004
//Problem:	Lab 5 
//Date:		2/20/2020

#include <stdio.h>

void q2(){
	printf("\n\n\nThis is a calculator of size of a type.");
	while(1 < 3){
		printf("\n0) int type");
		printf("\n1) char type");
		printf("\n2) float type");
		printf("\n3) double type");
		printf("\n4) long type");
		printf("\n5) long double type");
		printf("\n6) Exit");
		
		printf("\n\nPlease type a number to select a type: ");
		int x;
		scanf("%d", &x);
		switch(x) {
			case 0:
				printf("\nThe size of int in byte is: %d bytes\n", (int) sizeof(int));
				break;
			case 1:
				printf("\nThe size of int in byte is: %d bytes\n", (int) sizeof(char));
				break;
			case 2:
				printf("\nThe size of int in byte is: %d bytes\n", (int) sizeof(float));
				break;
			case 3:
				printf("\nThe size of int in byte is: %d bytes\n", (int) sizeof(double));
				break;
			case 4:
				printf("\nThe size of int in byte is: %d bytes\n", (int) sizeof(long));
				break;
			case 5:
				printf("\nThe size of int in byte is: %d bytes\n", (int) sizeof(long double));
				break;
			case 6:
				break;
		} if (x==6){
			break;
		}
	}
}

void q3(){
	int x;
	int k = 0;
	int arr[10];
	printf("\n\n\nPlease input a sequence of numbers ended by 0:\n");
    while(1 < 2) {
		scanf("%d", &x);
		if(x == 0){
			break;
		} else {
			arr[k] = x;
			k++;
		}
	}
	int j = k;
	printf("\nThe numbers in the reverse order of your input are: ");
	while(k > 0) {
		printf("%d ", arr[k-1]);
		k--;
		if (k <= 0){
			break;
		}
	}	
	int min = arr[0];
	printf("\nThe minimal number of them is ");
	for(int i = 0; i < j; i++){
		if(min > arr[i]){
			min = arr[i];
		}
	}
	printf("%d.\n\n\n", min);
}

int main(){
	while(1 < 3){
		printf("\n2) Go to question 2");
		printf("\n3) Go to question 3");
		printf("\n4) Exit");
		printf("\n\nPlease type a number from 2 to 4 to select menu item: ");
		int x;
		scanf("%d", &x);
		switch(x) { 
			case 2:
				q2();
				break;
			case 3:
				q3();
				break;
			case 4:
				break;
		} if(x==4){
			break;
		}
	}	
} 