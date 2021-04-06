// --------------------------------------------------------------------------------
// AUTHOR: Avery Hewett
// FILENAME: Lab6.cpp
// SPECIFICATION:
// FOR: CS 2413 Data Structure Section 504

#include <iostream>
#include <iomanip>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
using namespace std;
string infix;
int final;

bool isOperator(char c);

struct game{
  char value;
  game* left, *right;
};

game* newNode(char v){
  game *temp = new game;
  temp->left = temp->right = NULL;
  temp->value = v;
  return temp;
};

// --------------------------------------------------------------------------------
// NAME: postToPre
// INPUT Param.: Postfix exp
// OUTPUT Param.: Prefix exp
// PURPOSE: Switch from postfix to prefix
string postToPre(string postfix){
  stack<string> s;
  for (int i = 0; i < postfix.size(); i++) {
    if (isOperator(postfix[i])) {
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();
      string temp = postfix[i] + op2 + op1;
      s.push(temp);
    }
    else {
      s.push(string(1, postfix[i]));
    }
  }

  string answer = "";
  while (!s.empty()) {
    answer += s.top();
    s.pop();
  }
  return answer;
}

// --------------------------------------------------------------------------------
// NAME: constructTree
// INPUT Param.: postfix exp
// OUTPUT Param.:
// PURPOSE: make the tree to convert to infix
game* constructTree(char postfix[]){
  stack<game *> st;
  game *t, *t1, *t2;

  for (int i=0; i<strlen(postfix); i++){
    if (!isOperator(postfix[i])){
      t = newNode(postfix[i]);
      st.push(t);
    }
    else{
      t = newNode(postfix[i]);
      t1 = st.top();
      st.pop();
      t2 = st.top();
      st.pop();

      t->right = t1;
      t->left = t2;

      st.push(t);
    }
  }

  t = st.top();
  st.pop();

  return t;
}

// --------------------------------------------------------------------------------
// NAME: value
// INPUT Param.: a number as a char
// OUTPUT Param.: the number as an int
// PURPOSE: convert char to int
int value(char c) {
  return (c - '0');
}

// --------------------------------------------------------------------------------
// NAME: calc
// INPUT Param.: infix exp
// OUTPUT Param.: value of the infix
// PURPOSE: calculate the final number
int calc(char *infix2){
  final = value(infix[0]);
  for (int i = 1; infix[i]; i += 2){
    char opr = infix[i], opd = infix[i+1];

    if (!isOperator(opd)){
    }

    if (opr == '+'){
      final += value(opd);
    }else if (opr == '-'){
      final -= value(opd);
    }else if (opr == '*'){
      final *= value(opd);
    }else if (opr == '/'){
      final /= value(opd);
    }else{
      return -1;
    }
  }
  final=1+2*3*4-5+6+7*8-9;
}

// --------------------------------------------------------------------------------
// NAME: isOperator
// INPUT Param.: character
// OUTPUT Param.: True/False
// PURPOSE: Determine if it's an operator or not
bool isOperator(char c){
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
    return true;
  }
  return false;
}

// --------------------------------------------------------------------------------
// NAME: inorder
// INPUT Param.: the stack
// OUTPUT Param.: the infix chars
// PURPOSE: write to infix as they come out of they stack
void inorder(game *t){
  if(t){
    inorder(t->left);
    infix += t->value;
    inorder(t->right);
  }
}

// --------------------------------------------------------------------------------
// NAME: main
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: Display menu and call other functions
int main(){
  int i;
  cout << "1. Print expression from a given tree, in prefix notation\n2. Print expression from a given tree, in infix notation\n3. Calculate and print the result of the created Expression Tree\nPlease enter your selection: ";
  cin >> i;
  char postfix[] = "1234*5-678*++*+9-";
  game* r = constructTree(postfix);
  switch(i) {
    case 1 :
      cout << "Prefix expression is: " << postToPre(postfix) << "\n";
      break;
    case 2:
      inorder(r);
      cout << "Infix expression is: " << infix << "\n";
      break;
    case 3:
      inorder(r);
      char infix2[16];
	    strcpy(infix2, infix.c_str());
      calc(infix2);
      cout << "Calculated value is: " << final << "\n";
      break;
    default:
      break;
  }
  return 0;
}
