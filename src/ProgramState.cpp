#include "../lib/ProgramState.h"

using namespace std;


ProgramState::ProgramState(int numLines) { //constructor
	m_numLines = numLines-1;
	programCounter = 1;
	toEnd = false;
}

void ProgramState::upProgramCounter(){ //+1 to program counter
	programCounter++;
}

void ProgramState::setProgramCounter(int num){ //set the program counter
	programCounter = num;
}

int ProgramState::getProgramCounter(){ //returns the program counter
	return programCounter;
}

bool ProgramState::exists(string name){ //returns true if variable exists already
	map<string,int>::iterator it;
	it = myMap.find(name);
  	if(it != myMap.end()){
  		return true;
  	}
  	return false;
} 

int ProgramState::getLines(){ // returns number of lines
	return m_numLines;
}

void ProgramState::update(string name, int val){ // updates value of name to val
	myMap[name] = val;
}

void ProgramState::printAll(ostream &outf){
	//iterator
	map<string, int>::iterator it;
	for(it = myMap.begin( ); it != myMap.end( ); ++it)
	{
		outf<< it->first << " " << it->second<< endl;
	}
}

map<string, int> ProgramState::getList(){
	return myMap;
}

bool ProgramState::shouldEnd() { // returns true when the program should terminate
	return toEnd;
}

void ProgramState::setEnd() // sets toEnd to true
{
	toEnd = true;
}

void ProgramState::create(string name, int val){ // creates variable name with val
	myMap.insert(pair<string,int>(name,val) );
}

int ProgramState::get(string name){ // returns the value of variable name
	return myMap[name];
}