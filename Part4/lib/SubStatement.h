// SubStatement.h
//
// CS 104 / Spring 2016
//
// The SubStatement class encapsulates a SUB statement in a Facile program.
// A SUB statement looks like this:
//
//     SUB VAR 3
//			or
//	   SUB VAR VAL 
//
// Primarily, it consists of two things: a variable name and either another
// variable name or integer value. It subtracts the second variable or integer from the
// variable in the first position. The second value is not modified. 

#ifndef SUB_STATEMENT_INCLUDED
#define SUB_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class SubStatement: public Statement
{
	private:
		std::string m_variableName;
		std::string m_variableNameTwo;
		int m_value;
		int construct;

	public:
		SubStatement(std::string variableName, int value);
		SubStatement(std::string variableName, std::string variableNameTwo);
		virtual ~SubStatement();
		virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif