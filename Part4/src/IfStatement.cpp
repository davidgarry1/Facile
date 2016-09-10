#include "../lib/IfStatement.h"
using namespace std;

IfStatement::~IfStatement()
{
	//nothing to do here
}

IfStatement::IfStatement(string one, string two, int three, int four)
{
	uno = one;
	dos = two;
	tres = three;
	jump = four;
}

void IfStatement::execute(ProgramState * state, ostream &outf)
{
	outf << "";
	if(!state->exists(uno))
	{
		state->create(uno, 0);
	}
	state->upProgramCounter();
	if(dos == "<")
	{
		if(state->get(uno) < tres)
		{
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
	}
	if(dos == "<=")
	{
		if(state->get(uno) <= tres)
		{
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
	}
	if(dos == ">")
	{
		if(state->get(uno) > tres)
		{
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
	}
	if(dos == ">=")
	{
		if(state->get(uno) >= tres)
		{
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
	}
	if(dos == "=")
	{
		if(state->get(uno) == tres)
		{
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
	}
	if(dos == "<>")
	{
		if(state->get(uno) != tres)
		{
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
	}
}