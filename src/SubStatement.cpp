#include "../lib/SubStatement.h"
using namespace std;

SubStatement::~SubStatement()
{
	//nothing to do here
}

SubStatement::SubStatement(std::string variableName, int value){
	m_variableName = variableName;
	m_variableNameTwo = "";
	m_value = value;
	construct =1;
}

SubStatement::SubStatement(std::string variableName, std::string variableNameTwo){
	m_variableName = variableName;
	m_variableNameTwo = variableNameTwo;
	m_value = 0;
	construct =2;
}

void SubStatement::execute(ProgramState * state, ostream &outf)
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
	three = one - two; // subtract the second value from the first
	state->update(m_variableName, three);
}