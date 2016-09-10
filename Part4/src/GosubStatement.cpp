#include "../lib/GosubStatement.h"
using namespace std;

GosubStatement::~GosubStatement()
{
	//nothing to do here
}

GosubStatement::GosubStatement(int line)
{
	jump = line;
}

void GosubStatement::execute(ProgramState * state, ostream &outf)
{
	outf << "";
	if((jump < 0) || (jump > state->getLines()))
	{
		throw std::runtime_error("Illegal jump instruction");
		state->setEnd();
	}
	else
	{
		state->stack.push(state->getProgramCounter()+1);
		state->setProgramCounter(jump);
	}
}