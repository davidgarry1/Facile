#include "../lib/DivStatement.h"
using namespace std;

DivStatement::~DivStatement()
{
	//nothing to do here
}

DivStatement::DivStatement(std::string variableName, int value){
	m_variableName = variableName;
	m_variableNameTwo = "";
	m_value = value;
	construct =1;
}

DivStatement::DivStatement(std::string variableName, std::string variableNameTwo){
	m_variableName = variableName;
	m_variableNameTwo = variableNameTwo;
	m_value = 0;
	construct =2;
}

void DivStatement::execute(ProgramState * state, ostream &outf)
{
	outf << "";
	state->upProgramCounter();
	if(!state->exists(m_variableName)) //if it does not exist
	{
		state->create(m_variableName, 0); // create it
	}
	int one = state->get(m_variableName); // first value stored
	int two, three;
	if(construct == 1) // if an integer was passed directly
	{
		two = m_value; // store second value
	}
	else // a variable was passed in the second perameter
	{
		if(!state->exists(m_variableNameTwo)) //if it does not exist
		{
			state->create(m_variableNameTwo, 0); //create it
		}
		two = state->get(m_variableNameTwo); // store second value
	}
	if(two == 0)
	{
		throw std::overflow_error("Divide by Zero Exception");
	}
	three = one/two; // divide the values
	state->update(m_variableName, three);
}