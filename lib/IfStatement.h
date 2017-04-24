// IfStatement.h
//
// CS 104 / Spring 2016
//
// The IfStatement class encapsulates an IF statement in a Facile program.
// An IF statement looks like this:
//
//     IF VAR < 3 THEN 2
//
// Primarily, it consists of four things: a variable, an operator (<, <=, >, >=, =, <>),
// an integer value, and another integer value. It compares the first integer value to
// the variable using the operator, and then if the comparison yeilds a value
// of true, execution of the program is jumped to the line number of the last integer.

#ifndef IF_STATEMENT_INCLUDED
#define IF_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class IfStatement: public Statement
{
	private:
		std::string uno;
		std::string dos;
		int tres;
		int jump;
		
	public:
		IfStatement(std::string one, std::string two, int three, int four);
		virtual ~IfStatement();
		virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif