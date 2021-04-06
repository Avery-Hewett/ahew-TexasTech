// --------------------------------------------------------------------------------
// AUTHOR: Avery Hewett
// FILENAME: Lab4.cpp
// SPECIFICATION: Change from base 10 to base 2-27
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
// PURPOSE: Divide and modulus to find the remainder to turn into another base
int main () {
  int number;
  int base;
  stack <char> s;
  s.push('Z');
  cout << "Please enter the number you'd like to convert: ";
  cin >> number;
  cout << "Please enter the base you'd like to convert to: ";
  cin >> base;
  int remain;
  int fnum = number;
  while(number >= base){
    remain = number % base;
    if (remain == 0){
      s.push('0');
    }else if(remain == 1){
      s.push('1');
    }else if(remain == 2){
      s.push('2');
    }else if(remain == 3){
      s.push('3');
    }else if(remain == 4){
      s.push('4');
    }else if(remain == 5){
      s.push('5');
    }else if(remain == 6){
      s.push('6');
    }else if(remain == 7){
      s.push('7');
    }else if(remain == 8){
      s.push('8');
    }else if(remain == 9){
      s.push('9');
    }else if(base > 10 && remain == 10){
      s.push('A');
    }else if(base > 10 && remain == 11){
      s.push('B');
    }else if(base > 10 && remain == 12){
      s.push('C');
    }else if(base > 10 && remain == 13){
      s.push('C');
    }else if(base > 10 && remain == 14){
      s.push('E');
    }else if(base > 10 && remain == 15){
      s.push('F');
    }else if(base > 10 && remain == 16){
      s.push('G');
    }else if(base > 10 && remain == 17){
      s.push('H');
    }else if(base > 10 && remain == 18){
      s.push('I');
    }else if(base > 10 && remain == 19){
      s.push('J');
    }else if(base > 10 && remain == 20){
      s.push('K');
    }else if(base > 10 && remain == 21){
      s.push('L');
    }else if(base > 10 && remain == 22){
      s.push('M');
    }else if(base > 10 && remain == 23){
      s.push('N');
    }else if(base > 10 && remain == 24){
      s.push('O');
    }else if(base > 10 && remain == 25){
      s.push('P');
    }else if(base > 10 && remain == 26){
      s.push('Q');
    }else if(base > 10 && remain == 27){
      s.push('R');
    }
    number = number / base;
  }
  if (number == 0){
    s.push('0');
  }else if(number == 1){
    s.push('1');
  }else if(number == 2){
    s.push('2');
  }else if(number == 3){
    s.push('3');
  }else if(number == 4){
    s.push('4');
  }else if(number == 5){
    s.push('5');
  }else if(number == 6){
    s.push('6');
  }else if(number == 7){
    s.push('7');
  }else if(number == 8){
    s.push('8');
  }else if(number == 9){
    s.push('9');
  }else if(base > 10 && number == 10){
    s.push('A');
  }else if(base > 10 && number == 11){
    s.push('B');
  }else if(base > 10 && number == 12){
    s.push('C');
  }else if(base > 10 && number == 13){
    s.push('C');
  }else if(base > 10 && number == 14){
    s.push('E');
  }else if(base > 10 && number == 15){
    s.push('F');
  }else if(base > 10 && number == 16){
    s.push('G');
  }else if(base > 10 && number == 17){
    s.push('H');
  }else if(base > 10 && number == 18){
    s.push('I');
  }else if(base > 10 && number == 19){
    s.push('J');
  }else if(base > 10 && number == 20){
    s.push('K');
  }else if(base > 10 && number == 21){
    s.push('L');
  }else if(base > 10 && number == 22){
    s.push('M');
  }else if(base > 10 && number == 23){
    s.push('N');
  }else if(base > 10 && number == 24){
    s.push('O');
  }else if(base > 10 && number == 25){
    s.push('P');
  }else if(base > 10 && number == 26){
    s.push('Q');
  }else if(base > 10 && number == 27){
    s.push('R');
  }
  string f = "";
  char c;
  while(s.top() != 'Z'){
    c = s.top();
    f += c;
    s.pop();
  }
  cout << fnum << " in base " << base << " is: " << f << "\n";
  return 0;
}
