#include "../lib/GotoStatement.h"
using namespace std;

GotoStatement::~GotoStatement()
{
	//nothing to do here
}

GotoStatement::GotoStatement(int line)
{
	jump = line;
}

void GotoStatement::execute(ProgramState * state, ostream &outf)
{
	outf << "";
	if((jump < 0) || (jump > state->getLines()))
	{
		throw std::runtime_error("Illegal jump instruction");
		state->setEnd();
	}
	else
	{
		state->setProgramCounter(jump);
	}
}