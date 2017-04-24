#include "../lib/EndStatement.h"


EndStatement::EndStatement()
{
	//nothing to do here
}

EndStatement::~EndStatement()
{
	//nothing to do here
}


void EndStatement::execute(ProgramState * state, std::ostream &outf)
{
	outf << "";
	state->upProgramCounter();
	state->setEnd(); // make the program terminate
}