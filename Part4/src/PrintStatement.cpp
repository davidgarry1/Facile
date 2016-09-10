// PrintStatement.cpp:
#include "../lib/PrintStatement.h"

PrintStatement::~PrintStatement()
{
	//nothing to do here
}

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}

void PrintStatement::execute(ProgramState * state, std::ostream &outf)
{
	outf << "";
	state->upProgramCounter();
	if(!(state->exists(m_variableName)))
	{
		state->create(m_variableName, 0);
	}
	int printing = state->get(m_variableName);
	outf<<printing<<std::endl;
}