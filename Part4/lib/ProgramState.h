// ProgramState.h
//
// CS 104 / Spring 2016
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a Facile program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// I've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED

#include "stackint.h"
#include <map>
#include <string>
#include <iostream>

class ProgramState
{
	public:
		int programCounter;
		ProgramState(int numLines);
		// You'll need to add a variety of methods here.  Rather than trying to
		// think of what you'll need to add ahead of time, add them as you find
		// that you need them.

		void upProgramCounter(); //+1 to program counter
		void setProgramCounter(int line); //set the program counter
		int getProgramCounter(); // returns the program counter
		bool exists(std::string name); //returns true if variable exists already
		void update(std::string name, int val); // updates value of name to val
		void create(std::string name, int val); // creates variable name with val
		int get(std::string name); // returns the value of variable name
		bool shouldEnd(); // returns true if the program state should terminate
		void setEnd(); // sets toEnd to true
		void printAll(std::ostream &outf); // prints all the values stored in myMap
		int getLines(); // returns m_numLines
		std::map<std::string, int> getList(); //returns the full list of stored items
		StackInt stack;

	private:
		int m_numLines;
		bool toEnd;
		std::map<std::string, int> myMap;
};

#endif