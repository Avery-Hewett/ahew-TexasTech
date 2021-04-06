//Name: 	Avery Hewett
//Group:	Eric Johnson
//Section:	Lab 504/Lecture 004
//Problem:	Lab 6 
//Date:		3/5/2020

#include <stdio.h>

void search(int arr[], int k){
	int x;
	printf("\n\nEnter the number you would like to search for: ");
	scanf("%d", &x);
	for(k = k; k>= 0 ; --k){
		if(arr[k] == x){
			printf("\n\n%d is in the array.", x); 
			return ;
		}
	}
	printf("\n\n%d is not in the series.\n", x);
}

void size(int arr[10]){
	int x;
	int k = 0;
	printf("\n\n\nInput numbers in ascending order:\n");
    for(int i = 0;i < 10;i++) {
		scanf("%d", &x);
		if(x != 0){
			arr[k] = x;
			k++;
		} else { 
			break;
		}
	}
	search(arr, k);
}

int main(){
	int arr[10];
	size(arr);
}