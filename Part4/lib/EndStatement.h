// EndStatement.h
//
// CS 104 / Spring 2016
//
// The EndStatement class encapsulates an END statement in a Facile program.
// An END statement looks like this:
//
//     END
//
// The END statement is used to terminate the program if reached. If an END
// statement is skipped over, however, it does not end the program.

#ifndef END_STATEMENT_INCLUDED
#define END_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class EndStatement: public Statement
{
	public:
		EndStatement();
		virtual ~EndStatement();
		virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif