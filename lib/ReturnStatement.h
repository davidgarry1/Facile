// ReturnStatement.h
//
// CS 104 / Spring 2016
//
// The ReturnStatement class encapsulates an RETURN statement in a Facile program.
// A RETURN statement looks like this:
//
//     RETURN
//
// A RETURN statement jumps execution of the program back to the line after
// the most recently called GOSUB statement.



#ifndef Return_STATEMENT_INCLUDED
#define Return_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include <iostream>

class ReturnStatement: public Statement
{
	public:
		ReturnStatement();
		virtual ~ReturnStatement();
		virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif