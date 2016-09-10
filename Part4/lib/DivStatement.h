// DivStatement.h
//
// CS 104 / Spring 2016
//
// The DivStatement class encapsulates a DIV statement in a Facile program.
// A DIV statement looks like this:
//
//     DIV VAR 3
//			or
//	   DIV VAR VAL 
//
// Primarily, it consists of two things: a variable name and either another
// variable name or integer value. It divides the first variable by the
// variable or integer in the secon position. The second value is not modified. 


#ifndef DIV_STATEMENT_INCLUDED
#define DIV_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"


class DivStatement: public Statement
{
	private:
		std::string m_variableName;
		std::string m_variableNameTwo;
		int m_value;
		int construct;

	public:
		DivStatement(std::string variableName, int value);
		DivStatement(std::string variableName, std::string variableNameTwo);
		virtual ~DivStatement();
		virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif