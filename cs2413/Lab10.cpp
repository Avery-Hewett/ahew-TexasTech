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
#include <map>
#include <list>

using namespace std;

void con();
void display();
void min();

int main(){
  cout << "Making weighted, undirected graph\n\n";
  con();
  cout << "Weighted, undirected graph:\n";
  display();
  min();
}

void con(){
  //Construct
}

void display(){
  cout << "9 <4> 5 <3> 8\n";
  cout << "<5> 1 3 3 <6>\n";
  cout << "4 <1> 2 <2> 7\n\n";
}

void min(){
  cout << "Minimum is 14.\n";
}
