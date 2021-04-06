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

class Hash
{
    int memory;
    list<int> *table;

public:
    Hash(int V);
    void insert(int x);
    int memoryLoc(int x) {
        return (x % memory);
    }
    void display();
};

Hash::Hash(int b)
{
    this->memory = b;
    table = new list<int>[memory];
}

// -----------------------------------------------------------------------------
// NAME: insert
// INPUT Param.: the key
// OUTPUT Param.: none
// PURPOSE: inserts the key into proper place in memory
void Hash::insert(int key)
{
    int index = memoryLoc(key);
    table[index].push_back(key);
}

// -----------------------------------------------------------------------------
// NAME: display
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: display memory locations
void Hash::display() {
  for (int i = 0; i < memory; i++) {
    cout << i << ": ";
    for (auto x : table[i])
      cout << x << " -> ";
    cout << endl;
  }
}

// -----------------------------------------------------------------------------
// NAME: main
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: call other functions
int main(){
  cout << "Starting hashing with chaining using a table with the keys 7, 24, 18, 52, 36, 54, 11, and 23\n\n";
  int a[8] = {7, 24, 18, 52, 36, 54, 11, 23};
  Hash h(9);
  for (int i = 0; i < 8; i++){
    h.insert(a[i]);
  }

  h.display();
  return 0;
}
