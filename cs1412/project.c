//Name: 	Avery Hewett
//Group:	Eric Johnson
//Section:	Lab 504/Lecture 004
//Problem:	Project 
//Date:		4/14/2020
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
     char name[30];
   	 int balance;
	 int gain;
} players;

players record[9];

int file(){
	FILE *fptr;
	fptr = fopen("players.txt", "r");
	if (fptr == NULL){
        printf("\nERROR: Could not open file players.txt");
        return 0;
    } 
	
	char word[30];
	int bal;
	int gain;
	int i = 0;
	while(fscanf(fptr, "%s\t%d\t%d\n", word, &bal, &gain) != EOF){
		strcpy(record[i].name, word);
		record[i].balance = bal;
		record[i].gain = gain;
		i++;
	}
	fclose (fptr);
}

int option0(){
	printf("\n\nPlease enter your name: ");
	char name[30];
	scanf("%s", name);
	for(int i = 0; i < 10; i++){
		if(strcmp(name, record[i].name) == 0){
			printf("\nWhat would you like to make your balance: ");
			int bal;
			scanf("%d", &bal);
			record[i].balance = bal;
			return 0;
		}
	}
	printf("\nERROR: Name not found");
}

int option1(){
	printf("\n\nPlease enter your name: ");
	char name[30];
	scanf("%s", name);
	getchar();
	int dice1;
	int dice2;
	int sum;
	int pointvalue;
	int j = 0;
	for(int i = 0; i < 10; i++){
		if(strcmp(name, record[i].name) == 0){
			while(1){
				printf("\nPress enter to roll the dice\n");
				char enter = 0;
				while (enter != '\r' && enter != '\n') { 
					enter = getchar(); 
				}	
				dice1 = rand()%6 + 1;
				dice2 = rand()%6 + 1;
				sum = dice1 + dice2;
				printf("\nThe values of the dices are %d and %d whose sum is %d.", dice1, dice2, sum);
				
				if(j == 0){
					if(sum == 7 || sum == 11){
						record[i].balance = record[i].balance + 10;
						record[i].gain = record[i].gain + 10;
						printf("\nYou win the game. Your current balance is %d.", record[i].balance);
						printf("\n\nWould you like to play again?\n0) Yes\n1) No\nPlease enter a choice: "); 
						int x;
						scanf("%d", &x);
						switch(x) {
							case 0:
								break;
							case 1:
								return 0;		
						}
					}else if(sum == 2 || sum == 3 || sum == 12){
						record[i].balance = record[i].balance - 1;
						record[i].gain = record[i].gain - 1;
						printf("\nYou lose the game. Your current balance is %d.", record[i].balance);
						printf("\n\nWould you like to play again?\n0) Yes\n1) No\nPlease enter a choice: "); 
						int x;
						scanf("%d", &x);
						switch(x) {
							case 0:
								break;
							case 1:
								return 0;
						}
					}else{
						pointvalue = sum;
					}
					j++;
				}else{
					if(pointvalue == sum){
						record[i].balance = record[i].balance + 10;
						record[i].gain = record[i].gain + 10;
						printf("\nYou win the game. Your current balance is %d.", record[i].balance);
						printf("\n\nWould you like to play again?\n0) Yes\n1) No\nPlease enter a choice: "); 
						int x;
						scanf("%d", &x);
						switch(x) {
							case 0:
								break;
							case 1:
								return 0;		
						}
					}else if(sum == 7){
						record[i].balance = record[i].balance - 1;
						record[i].gain = record[i].gain - 1;
						printf("\nYou lose the game. Your current balance is %d.", record[i].balance);
						printf("\n\nWould you like to play again?\n0) Yes\n1) No\nPlease enter a choice: "); 
						int x;
						scanf("%d", &x);
						switch(x) {
							case 0:
								break;
							case 1:
								return 0;
						}
					}
				
				}
			}
		}	
	}
	printf("\nERROR: Name not found");
}

int option2(){
	int first = 0;
	char name1[30];
	int second = 0;
	char name2[30];
	int third = 0;
	char name3[30];
	int fourth = 0;
	char name4[30];
	int fifth = 0;
	char name5[30];
	
	for(int i = 0; i < 10; i++){
		if(record[i].balance > first){
			fifth = fourth;
			strcpy(name5, name4);
			fourth = third;
			strcpy(name4, name3);
			third = second;
			strcpy(name3, name2);
			second = first;
			strcpy(name2, name1);
			first = record[i].balance;
			strcpy(name1, record[i].name);
		}else if(record[i].balance > second && record[i].balance < first){
			fifth = fourth;
			strcpy(name5, name4);
			fourth = third;
			strcpy(name4, name3);
			third = second;
			strcpy(name3, name2);
			second = record[i].balance;
			strcpy(name2, record[i].name);
		}else if(record[i].balance > third && record[i].balance < second){
			fifth = fourth;
			strcpy(name5, name4);
			fourth = third;
			strcpy(name4, name3);
			third = record[i].balance;
			strcpy(name3, record[i].name);
		}else if(record[i].balance > fourth && record[i].balance < third){
			fifth = fourth;
			strcpy(name5, name4);
			fourth = record[i].balance;
			strcpy(name4, record[i].name);
		}else if(record[i].balance > fifth && record[i].balance < fourth){
			fifth = record[i].balance;
			strcpy(name5, record[i].name);
		}
	}
	printf("\n\nThe top people by balances are:");
	printf("\n1) %s %d", name1, first);
	printf("\n2) %s %d", name2, second);
	printf("\n3) %s %d", name3, third);
	printf("\n4) %s %d", name4, fourth);
	printf("\n5) %s %d\n\n", name5, fifth);
}

int option3(){
	int first = 0;
	char name1[30];
	int second = 0;
	char name2[30];
	int third = 0;
	char name3[30];
	int fourth = 0;
	char name4[30];
	int fifth = 0;
	char name5[30];
	
	for(int i = 0; i < 10; i++){
		if(record[i].gain > first){
			fifth = fourth;
			strcpy(name5, name4);
			fourth = third;
			strcpy(name4, name3);
			third = second;
			strcpy(name3, name2);
			second = first;
			strcpy(name2, name1);
			first = record[i].gain;
			strcpy(name1, record[i].name);
		}else if(record[i].gain > second && record[i].gain < first){
			fifth = fourth;
			strcpy(name5, name4);
			fourth = third;
			strcpy(name4, name3);
			third = second;
			strcpy(name3, name2);
			second = record[i].gain;
			strcpy(name2, record[i].name);
		}else if(record[i].gain > third && record[i].gain < second){
			fifth = fourth;
			strcpy(name5, name4);
			fourth = third;
			strcpy(name4, name3);
			third = record[i].gain;
			strcpy(name3, record[i].name);
		}else if(record[i].gain > fourth && record[i].gain < third){
			fifth = fourth;
			strcpy(name5, name4);
			fourth = record[i].gain;
			strcpy(name4, record[i].name);
		}else if(record[i].gain > fifth && record[i].gain < fourth){
			fifth = record[i].gain;
			strcpy(name5, record[i].name);
		}
	}
	printf("\n\nThe top people by gains are:");
	printf("\n1) %s %d", name1, first);
	printf("\n2) %s %d", name2, second);
	printf("\n3) %s %d", name3, third);
	printf("\n4) %s %d", name4, fourth);
	printf("\n5) %s %d\n\n", name5, fifth);
}

int exitgame(){
	FILE * fp;
	int i;
	fp = fopen ("players.txt","w");
 
	for(i = 0; i < 10;i++){
		fprintf (fp, "%s\t%d\t%d\n", record[i].name, record[i].balance, record[i].gain);
	}
	fclose (fp);
	return 0;
}
	
int menu(){
	while(1){
		printf("\n0) Top up your balance");
		printf("\n1) Play Game");
		printf("\n2) Top 5 players by balance");
		printf("\n3) Top 5 winners by what they have won");
		printf("\n4) Exit the game");
		printf("\n   Please enter the number you would like to choose: ");
		int x;
		scanf("%d", &x);
		
		switch(x) {
			case 0:
				option0();
				break;
			case 1:
				option1();
				break;
			case 2:
				option2();
				break;
			case 3:
				option3();
				break;
			case 4:
				exitgame();
				return 0;
		}
	}
}

int main(){
	file();
	menu();
}