// --------------------------------------------------------------------------------
// AUTHOR: Avery Hewett
// FILENAME: Lab5.cpp
// SPECIFICATION: Make a binary search tree
// FOR: CS 2413 Data Structure Section 504

#include <iostream>
#include <iomanip>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// --------------------------------------------------------------------------------
// NAME: main
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: Make a menu, binary srearch tree, allow searching and deleting
int main () {
  int arr[10];// = {5,2,10,1,4,7,12};
  int random;
	srand(time(NULL));
	for (int j = 0; j < 10; j++) {
		random = rand() % 100;
    arr[j] = random;
	}

  int line2[2] = {0,0};
  int line3[4] = {0,0,0,0};
  int line4[8] = {0,0,0,0,0,0,0,0};
  for (int l = 1; l < 10; l++){
    if (arr[l] <= arr[0]){
      if(line2[0] == 0){
        line2[0] = arr[l];
      }else if (arr[l] <= line2[0]){
        if(line3[0] == 0){
          line3[0] = arr[l];
        }else if(arr[l] <= line3[0]){
          if(line4[0] == 0){
            line4[0] = arr[l];
          }else if(arr[l] <= line4[0]){
            //line 5
          }else{
            //line 5
          }
        }else{
          if(line4[1] == 0){
            line4[1] = arr[l];
          }else if(arr[l] <= line4[1]){
            //line 5
          }else{
            //line 5
          }
        }
      }else{
        if(line3[1] == 0){
          line3[1] = arr[l];
        }else if(arr[l] <= line3[1]){
          if(line4[2] == 0){
            line4[2] = arr[l];
          }else if(arr[l] <= line4[2]){
            //line 5
          }else{
            //line 5
          }
        }else{
          if(line4[3] == 0){
            line4[3] = arr[l];
          }else if(arr[l] <= line4[3]){
            //line 5
          }else{
            //line 5
          }
        }
      }
    }else{
      if (line2[1] == 0){
        line2[1] = arr[l];
      }else if (arr[l] <= line2[1]){
        if(line3[2] == 0){
          line3[2] = arr[l];
        }else if(arr[l] <= line3[2]){
          if(line4[4] == 0){
            line4[4] = arr[l];
          }else if(arr[l] <= line4[4]){
            //line 5
          }else{
            //line 5
          }
        }else{
          if(line4[5] == 0){
            line4[5] = arr[l];
          }else if(arr[l] <= line4[5]){
            //line 5
          }else{
            //line 5
          }
        }
      }else{
        if(line3[3] == 0){
          line3[3] = arr[l];
        }else if(arr[l] <= line3[3]){
          if(line4[6] == 0){
            line4[6] = arr[l];
          }else if(arr[l] <= line4[6]){
            //line 5
          }else{
            //line 5
          }
        }else{
          if(line4[7] == 0){
            line4[7] = arr[l];
          }else if(arr[l] <= line4[7]){
            //line 5
          }else{
            //line 5
          }
        }
      }
    }
  }
  cout << "Binary tree created with random intergers.";
  int i;
  while(i!=4){
    cout << "\n1. Display tree\n2. Search for a number\n3. Remove a number\nPlease enter your selection: ";
    cin >> i;
    switch(i) {
      case 1 :
        if(arr[0] != 0){
          cout << "\t" << arr[0] << "\n";
        }else{
          cout << "Error.";
          break;
        }

        if (line2[0] != 0){
          cout << "      " << line2[0] << " ";
        }else{
          cout << "      -";
        }
        if (line2[1] != 0){
          cout << " " << line2[1] << "\n";
        }else{
          cout << "-\n";
        }

        if (line3[0] != 0){
          cout << "    " << line3[0] << " ";
        }else{
          cout <<  "    - ";
        }
        if (line3[1] != 0){
          cout << line3[1] << " ";
        }else{
          cout << "-  ";
        }
        if (line3[2] != 0){
          cout << line3[2] << " ";
        }else{
          cout << "-  ";
        }
        if (line3[3] != 0){
          cout << line3[3] << "\n";
        }else{
          cout << "-\n";
        }

        if (line4[0] != 0){
          cout << line4[0] << " ";
        }else{
          cout << "- ";
        }
        if (line4[1] != 0){
          cout << line4[1] << " ";
        }else{
          cout << "- ";
        }
        if (line4[2] != 0){
          cout << line4[2] << " ";
        }else{
          cout << "- ";
        }
        if (line4[3] != 0){
          cout << line4[3] << " ";
        }else{
          cout << "- ";
        }
        if (line4[4] != 0){
          cout << line4[4] << " ";
        }else{
          cout << "- ";
        }
        if (line4[5] != 0){
          cout << line4[5] << " ";
        }else{
          cout << "- ";
        }
        if (line4[6] != 0){
          cout << line4[6] << " ";
        }else{
          cout << "- ";
        }
        if (line4[7] != 0){
          cout << line4[7] << "\n";
        }else{
          cout << "-\n";
        }
        break;
      case 2 :
        int num;
        cout << "\n\nEnter the number to search for: ";
        cin >> num;
        if(arr[0] == num){
          cout << "\n" << num << " Found at level 1\n";
        }else if(line2[0] == num || line2[1] == num){
          cout << "\n" << num << " Found at level 2\n";
        }else if(line3[0] == num || line3[1] == num || line3[2] == num || line3[3] == num){
          cout << "\n" << num << " Found at level 3\n";
        }else if(line4[0] == num || line4[1] == num || line4[2] == num || line4[3] == num || line4[4] == num || line4[5] == num || line4[6] == num || line4[7] == num){
          cout << "\n" << num << " Found at level 4\n";
        }else{
          cout << "\n" << num << " Not found!\n";
        }
        break;
      case 3 :
        int del;
        cout << "\n\nEnter the number to search for: ";
        cin >> del;
        if(arr[0] == del){
          cout << "\nCannot delete the top of the tree.\n";
        }else if(line2[0] == del || line2[1] == del){
          for (int q = 0; q < 2; q++){
            if (line2[q] == del){
              line2[q] = 0;
              cout << "\n" << del << " was deleted.\n";
              break;
            }
          }
        }else if(line3[0] == del || line3[1] == del || line3[2] == del || line3[3] == del){
          for (int w = 0; w < 4; w++){
            if (line3[w] == del){
              line3[w] = 0;
              cout << "\n" << del << " was deleted.\n";
              break;
            }
          }
        }else if(line4[0] == del || line4[1] == del || line4[2] == del || line4[3] == del || line4[4] == del || line4[5] == del || line4[6] == del || line4[7] == del){
          for (int e = 0; e < 8; e++){
            if (line4[e] == del){
              line4[e] = 0;
              cout << "\n" << del << " was deleted.\n";
              break;
            }
          }
        }else{
          cout << "\n" << del << " Not found!\n";
        }
        break;
      case 4 :
        break;
      default :
        break;
    }
  }
}
