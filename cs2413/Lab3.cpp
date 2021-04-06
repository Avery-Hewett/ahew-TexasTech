// --------------------------------------------------------------------------------
// AUTHOR: Avery Hewett
// FILENAME: Lab3.cpp
// SPECIFICATION: Check if expressions are balanced and do infix to postfix
// FOR: CS 2413 Data Structure Section 504
#include <iostream>
#include <iomanip>
#include <stack>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// --------------------------------------------------------------------------------
// NAME: isBalanced
// INPUT Param.: expr, the top of stack
// OUTPUT Param.: if it is balanced or not, true/false
// PURPOSE: check if there are equal (,[,{,},],) and in right order
// Is part of our example code that was provided
bool isBalanced(string expr) {
  stack <char> s;
  char c;
  for (int i = 0; i < expr.length(); i++) {
    if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
      s.push(expr[i]);
      continue;
    }
    switch (expr[i]) {
      case ')':
        c = s.top();
        s.pop();
        if (c == '{' || c == '[')
          return false;
        break;
      case '}':
        c = s.top();
        s.pop();
        if (c == '(' || c == '[')
          return false;
        break;
      case ']':
        c = s.top();
        s.pop();
        if (c == '(' || c == '{')
          return false;
        break;
    }
  }
  return (true);
}

// --------------------------------------------------------------------------------
// NAME: pemdas
// INPUT Param.: c, the operator
// OUTPUT Param.: value of pemdas
// PURPOSE: reads value of pemdas for itop
int pemdas(char c) {
  if (c == '^') {
    return 3;
  } else if (c == '*' || c == '/') {
    return 2;
  } else if (c == '+' || c == '-') {
    return 1;
  } else {
    return -1;
  }
}

// --------------------------------------------------------------------------------
// NAME: itop
// INPUT Param.: expr or the infix value
// OUTPUT Param.: f or the postfix value
// PURPOSE: convert the infix value to postfix value
void itop(string expr) {
  stack <char> s; // Stack of operators
  s.push('N'); // Final value in stack to prevent underflowing
  string f; // Final value to be printed
  for (int i = 0; i < expr.length(); i++) {
    if ((expr[i] >= 'a' && expr[i] <= 'z') || (expr[i] >= 'A' && expr[i] <= 'Z')) {
      f += expr[i];
    } else if (expr[i] == '(') {
      s.push('(');
    } else if (expr[i] == ')') {
      while (s.top() != 'N' && s.top() != '(') {
        char c = s.top();
        s.pop();
        f += c;
      }
      if(s.top() == '(') {
        char c = s.top();
        s.pop();
      }
    } else {
      while (s.top() != 'N' && pemdas(expr[i]) <= pemdas(s.top())) {
        char c = s.top();
        s.pop();
        f += c;
      }
      s.push(expr[i]);
    }

  }
  while(s.top() != 'N') {
    char c = s.top();
    s.pop();
    f += c;
  }
  cout << expr << " is now " << f << "\n";
}

// --------------------------------------------------------------------------------
// NAME: main
// INPUT Param.: none
// OUTPUT Param.: none
// PURPOSE: Call other functions after pushing things to the stack
int main () {
  stack <string> s;
  s.push("14*(6+5)");
  s.push("A-(C+B)/[12*D]");
  s.push("[8+(38-14)-10]+12");
  s.push("{44-[8+(3814)-10]+12}-7");
  s.push("(9/5)*celsius+32");
  s.push("3+4*4+5*(4+3)-1");
  s.push("(3+4*x)/5-10*(y-5)*(a+b+c)/x+9*(4/x+{9+x}/y)");
  s.push("(A*[x^2]+{B*y})+C");

  while(s.size() != 0){
    if (isBalanced(s.top())) {
      cout << s.top() << " is Balanced\n";
      s.pop();
    } else {
      cout << s.top() << " is Not Balanced\n";
      s.pop();
    }
  }
  //s.push("A-(B/C+D%E*F)/G)*H");
  itop("a+b*(c^d-e)^(f+g*h)-i");
  itop("A-(B/C+D*F)/G)*H");

  return 0;
}
