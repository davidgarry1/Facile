// LetStatement.cpp:
#include "../lib/LetStatement.h"
using namespace std;

LetStatement::~LetStatement()
{
	//nothing to do here
}

LetStatement::LetStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState * state, ostream &outf)
{
	// incrememnt the program counter
	// if the variable exists, update it
	// else add a new variable
	outf << "";
	state->upProgramCounter();
	if(state->exists(m_variableName))
	{
		state->update(m_variableName, m_value);
	}
	else
	{
		state->create(m_variableName, m_value);
	}
}