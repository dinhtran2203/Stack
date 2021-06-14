//
//  stack.h
//
//   Created on: Oct 3, 2020
//       Author: Dinh Tran
//

#ifndef STACK_H_
#define STACK_H_

class Stack
{
 public:
  class EmptyStack{};
  // exception class thrown when attempt made to pop from empty stack

  Stack ();
  // default constructor

  explicit Stack(int size = 50);
  // constructor
  // pre : none
  // post: default size is 50

  Stack(const Stack& s);
  // copy constructor
  // pre : A stack
  // post: none

  Stack& operator=(const Stack& rhs);
  // overloaded assignment operator
  // pre : a stack or none need
  // post: stack may change

  ~Stack();
  // destructor
  // pre : a stack
  // post: stack will be deallocate


  void push(int data);
  // adds data to stack
  // pre : none
  // post: changing stack

  int peek();
  // check the top value
  // pre : non-empty stack
  // post: none

  int pop();
  // removes and returns data from stack
  // can throw EmptyStack exception
  // pre : none
  // post: stack will change and throw empty stack exception

  bool isEmpty() const;
  // returns status of stack
  // pre : a stack
  // post: none

 private:
  int* list; // stack
  int max;    // size of stack
  int top;    // top of stack

  bool full() const;
  // returns status of stack

  bool isPrime(int num);
  // check if the push value is prime

  void resize();
  // allocates more stack memory
};



#endif /* STACK_H_ */
