#include "../lib/ReturnStatement.h"
using namespace std;

ReturnStatement::~ReturnStatement()
{
	//nothing to do here
}

ReturnStatement::ReturnStatement()
{
	//nothing to do here
}

void ReturnStatement::execute(ProgramState * state, ostream &outf)
{
	outf << "";
	state->setProgramCounter(state->stack.top());
	state->stack.pop(); // most recent GOSUB returned
}