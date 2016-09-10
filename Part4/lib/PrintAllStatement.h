// PrintAllStatement.h
//
// CS 104 / Spring 2016
//
// The PrintAllStatement class encapsulates a PRINTALL statement in a Facile program.
// A PRINTALL statement looks like this:
//
//     PRINTALL
//
// The PRINTALL statement outputs the values of every variable that has been used in
// the program so far, including instances where a previously unused variable is 
// created in a PRINT statement, in alphabetical order. 

#ifndef PRINTALL_STATEMENT_INCLUDED
#define PRINTALL_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include <iostream>

class PrintAllStatement: public Statement
{
public:
	PrintAllStatement();
	virtual ~PrintAllStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
