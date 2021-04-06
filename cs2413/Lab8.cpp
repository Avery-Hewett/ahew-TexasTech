// -----------------------------------------------------------------------------
// AUTHOR: Avery Hewett
// FILENAME: Lab8.cpp
// SPECIFICATION:
// FOR: CS 2413 Data Structure Section 504

#include <iostream>
#include <iomanip>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

//Global vars
int matrix[3][3];
int AtB, AtC, BtC, BtD, CtD;

void readCSV();
void createGraph();
void display();
int shortestDist();

// -----------------------------------------------------------------------------
// NAME: main
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: call other functions
int main(){
  readCSV();
  matrix[0][0] = AtB;
  matrix[2][0] = AtC;
  matrix[0][2] = BtD;
  matrix[1][1] = BtC;
  matrix[2][2] = CtD;
  cout << "Our graph: ";
  createGraph();
  cout << "\n\nOur display: \n";
  display();
  cout << "\n\nShortest Distance chart: \n";
  shortestDist();
  return 0;
}

// -----------------------------------------------------------------------------
// NAME: readCSV
// INPUT Param.: none
// OUTPUT Param.: the contents of lab8.cpp
// PURPOSE: read csv files
void readCSV(){
  //Have not implemented this yet, for now is hardcoded
  AtB = 8;
  AtC = 22;
  BtD = 15;
  BtC = 7;
  CtD = 18;
}

// -----------------------------------------------------------------------------
// NAME: createGraph
// INPUT Param.: params about distance
// OUTPUT Param.: the graph
// PURPOSE: create graph
void createGraph(){
  cout << "\n\tB";
  cout << "\n  " << AtB << "\t  " << BtD;
  cout << "\nA\t" << BtC << "\tD";
  cout << "\n  " << AtC << "\t  " << CtD;
  cout << "\n\tC";
}

// -----------------------------------------------------------------------------
// NAME: display
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: make the graph display
void display(){
  for(int x = 0; x < 3; x++){
    for(int y = 0; y < 3; y++){
      if(matrix[x][y] == NULL){
        if(x == 1 && y == 0){
          cout << "A";
        }else if(x == 0 && y == 1){
          cout << "B";
        }else if(x == 1 && y == 2){
          cout << "D";
        }else if(x == 2 && y == 1){
          cout << "C";
        }
      }else{
        cout << matrix[x][y];
      }
    }
    cout << "\n";
  }
}

// -----------------------------------------------------------------------------
// NAME: shortestDist
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: find shortest dist from A to D
int shortestDist(){
  char x;
  int toA, toB, toC, toD;
  cout << "Please enter the number you'd like to calculate: ";
  cin >> x;
  switch(x){
    case 'A':
      toA = 0;
      toB = AtB;
      toC = AtB + BtC;
      if(AtB + BtD < AtC + CtD){
        toD = AtB + BtD;
      }else{
        toD = AtC + CtD;
      }
      break;
    case 'B':
      toA = AtB;
      toB = 0;
      toC = BtC;
      toD = CtD;
      break;
    case 'C':
      toA = AtC;
      toB = BtC;
      toC = 0;
      toD = CtD;
      break;
    case 'D':
      if(AtB + BtD < AtC + CtD){
        toA = AtB + BtD;
      }else{
        toA = AtC + CtD;
      }
      toB = BtD;
      toC = CtD;
      toD = 0;
      break;
    default:
      cout << "Please enter a valid input from A, B, C, or D";
      return 0;
  }

  cout << "Source Node\tDestination Node\tShortest Distance\n";
  cout << x << "\tA\t" << toA << "\n";
  cout << x << "\tB\t" << toB << "\n";
  cout << x << "\tC\t" << toC << "\n";
  cout << x << "\tD\t" << toD << "\n";

  return 1;
}
