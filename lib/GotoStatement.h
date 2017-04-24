// GotoStatement.h
//
// CS 104 / Spring 2016
//
// The GotoStatement class encapsulates a GOTO statement in a Facile program.
// A GOTO statement looks like this:
//
//     GOTO 2
//
// Primarily, it consists of one thing: an integer value.
// It jumps the execution of the program to the correcsponding line number 
// of the integer. It does not return back to this point unless another
// statement sends the program counter back. This is how it differs from a
// GOSUB statement.

#ifndef GOTO_STATEMENT_INCLUDED
#define GOTO_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class GotoStatement: public Statement
{
	private:
		int jump;
		
	public:
		GotoStatement(int line);
		virtual ~GotoStatement();
		virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
