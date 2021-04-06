// --------------------------------------------------------------------------------
// AUTHOR: Avery Hewett
// FILENAME: Lab7.cpp
// SPECIFICATION: Make min_heap map
// FOR: CS 2413 Data Structure Section 504

include <iostream>
#include <iomanip>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int ar[11];
int fin[11];

void min_heapify(int loc);
void build_heap();
void delete_root();
void print_heap();

// --------------------------------------------------------------------------------
// NAME: main
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: Call other functions and get input
int main (){
  cout << "Please enter the 11 numbers you'd like to insert into the tree: ";
  cin >> ar[0] >> ar[1] >> ar[2] >> ar[3] >> ar[4] >> ar[5] >> ar[6] >> ar[7] >> ar[8] >> ar[9] >> ar[10];
  build_heap();
  cout << "\nHeap now built...\nPrinting...";
  print_heap();
  cout << "Deleting root of: " << fin[0];
  delete_root();
  cout << "\nRoot now deleted...\nPrinting...";
  print_heap();
  return 0;
}

// --------------------------------------------------------------------------------
// NAME: min_heapify
// INPUT Param.: loc: the location to start from
// OUTPUT Param.: none
// PURPOSE: organize the tree
void min_heapify(int loc){
  int temp;
  while(true){
    if(loc == 1){
      if(fin[0] > fin[1]){
        temp = fin[0];
        fin[0] = fin[1];
        fin[1] = temp;
      }
      break;
    }else if(loc == 2){
      if(fin[0] > fin[2]){
        temp = fin[0];
        fin[0] = fin[2];
        fin[2] = temp;
      }
      break;
    }else if(loc == 3){
      if(fin[1] > fin[3]){
        temp = fin[1];
        fin[1] = fin[3];
        fin[3] = temp;
      }
      loc = 1;
    }else if(loc == 4){
      if(fin[1] > fin[4]){
        temp = fin[1];
        fin[1] = fin[4];
        fin[4] = temp;
      }
      loc = 1;
    }else if(loc == 5){
      if(fin[2] > fin[5]){
        temp = fin[2];
        fin[2] = fin[5];
        fin[5] = temp;
      }
      loc = 2;
    }else if(loc == 6){
      if(fin[2] > fin[6]){
        temp = fin[2];
        fin[2] = fin[6];
        fin[6] = temp;
      }
      loc = 2;
    }else if(loc == 7){
      if(fin[3] > fin[7]){
        temp = fin[3];
        fin[3] = fin[7];
        fin[7] = temp;
      }
      loc = 3;
    }else if(loc == 8){
      if(fin[3] > fin[8]){
        temp = fin[3];
        fin[3] = fin[8];
        fin[8] = temp;
      }
      loc = 3;
    }else if(loc == 9){
      if(fin[4] > fin[9]){
        temp = fin[4];
        fin[4] = fin[9];
        fin[9] = temp;
      }
      loc = 4;
    }else if(loc == 10){
      if(fin[4] > fin[10]){
        temp = fin[4];
        fin[4] = fin[10];
        fin[10] = temp;
      }
      loc = 4;
    }
  }
}

// --------------------------------------------------------------------------------
// NAME: build_heap
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: call min_heapify for every input
void build_heap(){
  fin[0] = ar[0];
  for(int i = 1; i < 11; i++){
    fin[i] = ar[i];
    min_heapify(i);
  }
}

// --------------------------------------------------------------------------------
// NAME: delete_root
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: delete the smallest number
void delete_root(){
  int temp;
  fin[0] = fin[10];
  fin[10] = 0;
  while(true){
    if(fin[0] > fin[1]){
      temp = fin[0];
      fin[0] = fin[1];
      fin[1] = temp;
      if(fin[1] > fin[3]){
        temp = fin[1];
        fin[1] = fin[3];
        fin[3] = temp;
        if(fin[3] > fin[7]){
          temp = fin[3];
          fin[3] = fin[7];
          fin[7] = temp;
          break;
        }else if(fin[3] > fin[8]){
          temp = fin[3];
          fin[3] = fin[8];
          fin[8] = temp;
          break;
        }
        break;
      }else if(fin[1] > fin[4]){
        temp = fin[1];
        fin[1] = fin[4];
        fin[4] = temp;
        if(fin[4] > fin[9]){
          temp = fin[4];
          fin[4] = fin[9];
          fin[9] = temp;
          break;
        }
        break;
      }else{
        break;
      }
    }else if(fin[0] > fin[2]){
      temp = fin[0];
      fin[0] = fin[2];
      fin[2] = temp;
      if(fin[2] > fin[5]){
        temp = fin[2];
        fin[2] = fin[5];
        fin[5] = temp;
        break;
      }else if(fin[2] > fin[6]){
        temp = fin[2];
        fin[2] = fin[6];
        fin[6] = temp;
        break;
      }else{
        break;
      }
    }else{
      break;
    }
  }
}

// --------------------------------------------------------------------------------
// NAME: print_heap
// INPUT Param.: none
// OUTPUT Param.: the heap tree
// PURPOSE: print the heap tree
void print_heap(){
  cout << "\n" << fin[0] << "\n";
  cout << fin[1] << " " << fin[2] << "\n";
  cout << fin[3] << " " << fin[4] << " " << fin[5] << " " << fin[6] << "\n";
  cout << fin[7] << " " << fin[8] << " " << fin[9];
  if(fin[10] != 0){
    cout << " " << fin[10] << "\n\n";
  }else{
    cout << "\n\n";
  }
}
