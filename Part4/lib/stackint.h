// GosubStatement.h
//
// CS 104 / Spring 2016
//
// This is a stack of integer values used in the GOSUB and
// RETURN statements to make sure that execution is jumped
// back to the most recent GOSUB call after a RETURN statement.

#ifndef STACKINT_H
#define STACKINT_H
#include "llistint.h"

class StackInt {
 public:
  StackInt();
  ~StackInt();

  /**
   * Returns true if the stack is empty, false otherwise
   */
  bool empty() const;

  /**
   * Pushes a new value, val, onto the top of the stack
   */
  void push(const int& val);

  /**
   * Returns the top value on the stack
   */
  int const &  top() const;

  /**
   * Removes the top element on the stack
   */
  void pop();

 private:
  /** 
   * Single data member of the Stack.
   * We use composition to implement this Stack 
   */
  LListInt list;
};
#endif
