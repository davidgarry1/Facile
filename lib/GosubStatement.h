// GosubStatement.h
//
// CS 104 / Spring 2016
//
// The GosubStatement class encapsulates an GOSUB statement in a Facile program.
// A GOSUB statement looks like this:
//
//     GOSUB 2
//
// Primarily, it consists of one thing: an integer
// value. It jumps to the integer value, and continues on from there until
// it reaches a RETURN statement. The program then jumps back to the line
// directly after the most recent GOSUB statement. In this way, it is like
// a GOTO statement with the ability to return back later.

#ifndef GOSUB_STATEMENT_INCLUDED
#define GOSUB_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>

class GosubStatement: public Statement
{
	private:
		int jump;
		
	public:
		GosubStatement(int line);
		virtual ~GosubStatement();
		virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif