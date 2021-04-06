//Name: 	Avery Hewett
//Group:	Eric Johnson
//Section:	Lab 504/Lecture 004
//Problem:	Lab 9 
//Date:		4/6/2020
#include <stdio.h>
#include <string.h>
#define FSIZE 100

int compareStr(char great[100], char new[100]){
	if(great == new){
		return 0;
	}else{
		if(great[0] < new[0]){
			return 1;
		}else if(great[0] == new[0]){
			if(great[1] < new[1]){
				return 1;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}	
}

int readFile(){
	FILE *fptr;
    char fname[FSIZE];
    printf("Please input the file name: ");
	scanf("%s",fname);

    fptr = fopen(fname, "r");
    if (fptr == NULL){
        printf("\nCould not open file %s", fname);
        return 0;
    }
	int comp = 2;
	int i = 0;
	char word[100] = "a";
	char greatest[100] = " ";
	char tempName[100] = " ";
	char saved[100] = " ";
	while(fscanf(fptr, "%s", word) != EOF){
		if(i%2 != 0){
			comp = compareStr(greatest, word);
			if(comp == 1){
				strcpy(greatest, word);
				strcpy(saved, tempName);
			}
		}else{
			strcpy(tempName, word);
		}
		i++;
	}
	printf("\nThe full name whose last name is the greatest in the file is %s %s\n", saved, greatest);	
    fclose(fptr);
	return 0;
}

int main(){
	readFile();
}