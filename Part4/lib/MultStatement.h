// MultStatement.h
//
// CS 104 / Spring 2016
//
// The MultStatement class encapsulates a MULT statement in a Facile program.
// A MULT statement looks like this:
//
//     MULT VAR 3
//			or
//	   MULT VAR VAL 
//
// Primarily, it consists of two things: a variable name and either annother
// variable name or integer value. It multiplies the first variable by the
// variable or integer in the secon position. The second value is not modified. 

#ifndef MULT_STATEMENT_INCLUDED
#define MULT_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class MultStatement: public Statement
{
	private:
		std::string m_variableName;
		std::string m_variableNameTwo;
		int m_value;
		int construct;

	public:
		MultStatement(std::string variableName, int value);
		MultStatement(std::string variableName, std::string variableNameTwo);
		virtual ~MultStatement();
		virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif