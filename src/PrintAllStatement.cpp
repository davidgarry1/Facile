// PrintStatement.cpp:
#include "../lib/PrintAllStatement.h"

PrintAllStatement::~PrintAllStatement()
{
	//nothing to do here
}

PrintAllStatement::PrintAllStatement()
{
	//nothing to do here
}

void PrintAllStatement::execute(ProgramState * state, std::ostream &outf)
{
	outf << "";
	state->upProgramCounter();
	state->printAll(outf);
}