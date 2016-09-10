// AddStatement.h
//
// CS 104 / Spring 2016
//
// The AddStatement class encapsulates an ADD statement in a Facile program.
// An ADD statement looks like this:
//
//     ADD VAR 3
//			or
//	   ADD VAR VAL 
//
// Primarily, it consists of two things: a variable name and either another
// variable name or integer value. It adds the second variable or integer to the
// variable in the first position. The second value is not modified. 

#ifndef ADD_STATEMENT_INCLUDED
#define ADD_STATEMENT_INCLUDED

#include "Statement.h"
#include "ProgramState.h"

class AddStatement: public Statement
{
	private:
		std::string m_variableName;
		std::string m_variableNameTwo;
		int m_value;
		int construct;

	public:
		AddStatement(std::string variableName, int value);
		AddStatement(std::string variableName, std::string variableNameTwo);
		virtual ~AddStatement();
		virtual void execute(ProgramState * state, std::ostream &outf);
};

#endif