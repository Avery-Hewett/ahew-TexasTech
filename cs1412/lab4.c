//Name: 	Avery Hewett
//Group:	Sebastian Agulara, Oliver Farnun
//Section:	Lab 504/Lecture 004
//Problem:	Lab 4 
//Date:		2/18/2020

#include <stdio.h>

int main(){
	while(1 < 2){
		printf("\n0) Check balance.");
    	printf("\n1) Deposit.");
    	printf("\n2) Change Password.");
    	printf("\n3) Transfer money.");
    	printf("\n4) Exit.");
    	printf("\nPlease type a number from 0 to 4 to select menu item: ");
    	int x;
    	scanf("%d", &x);
   		switch(x) { 
			case 0:
           		printf("\nCheck balance.");
           		printf("\nPress ENTER key to continue your transactions\n\n");
				break;
       		case 1:
           		printf("\nDeposit.");
           		printf("\nPress ENTER key to continue your transactions\n\n");
				break;
        	case 2:
           		printf("\nChange Password.");
           		printf("\nPress ENTER key to continue your transactions\n\n");
				break;
       		case 3:
           		printf("\nTransfer money.");
           		printf("\nPress ENTER key to continue your transactions\n\n");
				break;
        	case 4:
            	break;
    	} if (x == 4){
			break;
		}
		
		getchar();
		getchar();
	}	
	printf("\nPlease enter your income: ");
    int i;
	float j;
    scanf("%d", &i);
	if(i<750){
		j = i * 0.01;
	} else if(i<2250){
		j = 7.5 + ((i-750) * 0.02);
	} else if(i<3750){
		j = 37.5 + ((i-2250) * 0.03);
	} else if(i<5250){
		j = 82.5 + ((i-3750) * 0.04);
	} else if(i<7000){
		j = 142.5 + ((i-5250) * 0.05);
	} else{
		j = 230 + ((i-7000) * 0.06);
	}
	printf("%0.2f is what you owe in tax", j);

}