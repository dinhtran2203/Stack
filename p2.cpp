//=====================================================
// Name			: Class assigment
// Author		: Dinh Tran
// Date			: Oct 3, 2020
// Purpose		: Test drive for stack class (for record purpose)
// Description		: Test constructor, copy, overload, pop, resize, peek function
//=====================================================

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "stack.h"

using namespace std;

void welcome();
// Print out welcome massage
// pre : None condition needed
// post: none

void pVal2Stack(Stack &s);
// add 10 random prime values to stack
// pre : empty stack or normal stack (could cause resize)
// post: none

void print(Stack s);
// print all number from stack
// pre : normal stack
// post: none

bool isPrime(int num);
// check if number is prime
// pre : take in parameter must be integer


const int SIZE = 10;              // Size of stack
const int MAXRAND = 100;          // Maximum random number

int main()
{
  int val[SIZE] = {2, 3, 5, 7, 8, 9, 11};   // Small list to do push
  Stack s(SIZE);

  welcome();                      // Welcome massage

  cout << "\n1. Test two fundamental function push and pop with "
      "is prime condition" << endl;
  cout << "\nTest push function" << endl;
  cout << "--------------------------" << endl;

  cout << "\nPush 2, 3, 5, 7, 8, 9, 11" << endl;
  for (int i = 0; i <= SIZE ;i++){
    s.push(val[i]);
  }

  cout << "\nTest pop function" << endl;
  cout << "----------------------------" << endl;
  cout << "Pop stack" << endl;
  while(!s.isEmpty()){              // if stack not empty the pop all value
    cout << s.pop() << " ";
  }
  cout << endl;

  cout << "\nTest pop empty stack and empty function" <<endl;
  cout << "----------------------------" << endl;
  cout << "Check if stack empty" << endl;
  if (s.isEmpty())
    cout << "\nStack is empty now pop empty stack" << endl << endl;

  // test pop empty stack
  try{
    cout << s.pop();
  }catch(Stack::EmptyStack){
    cout << "ERROR: Stack is empty" << endl;
  }

  cout << "==================================================" << endl;
  cout << "\n2. Test other function" << endl;
  cout << "\nAdd random prime values to stack" << endl << endl;
  pVal2Stack(s);      // Push 10 prime values to stack
  print(s);

  cout << "\n=======Test copy constructor=======" << endl;
  cout << "------------------------------------" << endl;

  cout << "Copy stack s to stack s1" << endl;
  Stack s1(s);
  cout << "\n-------------Original s--------------";
  print(s);
  cout << "Address: " << &s << endl;
  cout << "\n-----------Copy Stack s1--------------";
  print(s1);
  cout << "Address: " << &s1 << endl;

  cout << "\n======Empty stack s1======" << endl;   // empty stack s1
  while(!s1.isEmpty()){              // if stack not empty the pop all value
    s1.pop();
  }

  cout << "\n======Test overload operator=======" << endl;
  cout << "-----------------------------------" << endl;
  cout << "Make stack s2 = stack s" << endl;
  Stack s2 = s;
  cout << "\n-------------Original s--------------";
  print(s);
  cout << "Address: " << &s << endl ;
  cout << "---------Overload Stack s2------------";
  print(s2);
  cout << "Address: " << &s2 << endl;

  cout << "\n======Empty stack s2=======" << endl;   // empty stack s1
  while(!s2.isEmpty()){              // if stack not empty the pop all value
    s2.pop();
  }

  cout << "\n===========Test Resize=============" << endl;
  cout << "\n---------Original Stack------------";
  print(s);
  cout << "\nPush 2 to stack" << endl << endl;
  s.push(2);
  cout << "---------Stack after push 2----------";
  print(s);

  cout << "\n============Test peek==============" << endl;
  print(s);
  cout << "Peek value: " << s.peek() << endl;
  cout << "===========Program End=============" << endl << endl;

  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout << "This program is a test drive to all the function in stack class";
  cout << "\nStack will only take prime number" << endl;
  cout << "===============================================================";
  cout << endl;
  cout << "======================Program Start============================";
  cout << endl;
}

void pVal2Stack(Stack &s)
{
  int randNum;
  srand(time(0));
  cout << "This is add in number: " ;
  for (int i = 0; i < SIZE;i++){
    randNum = rand() % MAXRAND;
    if (isPrime(randNum)){
      cout << randNum << " ";
      s.push(randNum);
    }else{
      i--;
    }
  }
}

void print(Stack s)
{
  cout << "\nStack values: " << endl;
  cout << "top-> ";

  while (!s.isEmpty()){
    cout << s.pop() << " ";
  }
  cout << "<-bottom" << endl;
}

bool isPrime(int num)
{
  if (num <= 1){
    return false;
  }
  if (num <= 3){
    return true;
  }
  if (num % 2 == 0 or num % 3 == 0){
    return false;
  }
  for (int i = 5; i <= num/2; i++){
    if (num % i == 0){
      return false;
    }
  }
  return true;
}
