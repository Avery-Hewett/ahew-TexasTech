//Name: 	Avery Hewett
//Group:	Eric Johnson
//Section:	Lab 504/Lecture 004
//Problem:	Lab 8 
//Date:		3/30/2020
#include <stdio.h>

int getSeries(){
	int (*a)[10];
	int arr[10];
	int i = 0;
	int x;
	printf("\nInput a series of integers (ended with 0): ");
	while(i < 10) {
		scanf("%d", &x);
		if(x == 0){
			break;
		} else {
			arr[i] = x;
			i++;
		}
	}
	a = &arr;
	//
	printf("\nThe numbers in the reverse order of the input are: ");
	for(int n = i-1; n >= 0; n--){
		printf("%d ", *(*a + n));
	}
	//
	int max = 0;
	printf("\nThe maximal number of them is ");
	for(int j = 0; j < i; j++){
		if(*(*a + max) < *(*a + j)){
			max = j;
		}
	}
	printf("%d.\n", *(*a + max));
	//
	return i;
}

int main(){
	int n = getSeries();
}