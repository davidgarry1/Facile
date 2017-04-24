// PrintStatement.h
//
// CS 104 / Spring 2016
//
// The PrintStatement class encapsulates a PRINT statement in a Facile program.
// A PRINT statement looks like this:
//
//     PRINT VAR
//
// The PRINT statement outputs the value of the variable inputted. If the variable
// does not already exist, it will create the variable and initialize it to 0. In this
// way, if a PRINTALL statement is later called, a previously unused variable that
// was created in a PRINT statement will be included in the PRINTALL output.

#ifndef PRINT_STATEMENT_INCLUDED
#define PRINT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"
#include <iostream>

class PrintStatement: public Statement
{
private:
	std::string m_variableName;
	
public:
	PrintStatement(std::string variableName);
	virtual ~PrintStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif
