//mainwindow.cpp
#include "MainWindow.h"

using namespace std;

MainWindow::MainWindow()
{
	//SETUP ALL NECESSARY WINDOWS

	this->setWindowTitle("Load Window");
	loadButton = new QPushButton("Load");
	loadQuitButton = new QPushButton("Quit");
	edit = new QLineEdit("");
	loadLayout = new QVBoxLayout();
	loadLayout->addWidget(edit);
	loadLayout->addWidget(loadButton);
	loadLayout->addWidget(loadQuitButton);
	this->setLayout(loadLayout);
	connect(loadButton, SIGNAL(clicked()), this, SLOT(load()));
	connect(edit, SIGNAL(returnPressed()), loadButton, SIGNAL(clicked()));
	connect(loadQuitButton, SIGNAL(clicked()), this, SLOT(quit()));
	this->show();
	//this is the load window

	// Create message box
	errorBox = new QMessageBox();
	errorBox->setWindowTitle("Error Window");
	errorBox->setStyleSheet("background-color: pink;");

	//componenets of the debugger window
	scrollySet = false;
	Breakpoint_Button = new QPushButton("Add/Rm Breakpoint");
	connect(Breakpoint_Button, SIGNAL(clicked()), this, SLOT(addBP()));
	Continue_Button = new QPushButton("   Continue   ");
	connect(Continue_Button, SIGNAL(clicked()), this, SLOT(cont()));
	Step_Button = new QPushButton("     Step     ");
	connect(Step_Button, SIGNAL(clicked()), this, SLOT(step()));
	Next_Button = new QPushButton("     Next     ");
	connect(Next_Button, SIGNAL(clicked()), this, SLOT(next()));
	Inspect_Button = new QPushButton("   Inspect   ");
	connect(Inspect_Button, SIGNAL(clicked()), this, SLOT(inspect()));
	Quit_Button = new QPushButton("     Quit     ");
	connect(Quit_Button, SIGNAL(clicked()), this, SLOT(quit()));
	debugLayout = new QGridLayout();
	resultLabel = new QLabel("STARTED");
	scrolly = new QListWidget();
	debugWindow = new QWidget();
	//ROW, COL, ROWSPAN, COLSPAN
	debugLayout->addWidget(resultLabel, 0, 0, 1, 14, Qt::AlignCenter);
	debugLayout->addWidget(scrolly, 1, 0, 35, 14, Qt::AlignLeft);
	debugLayout->addWidget(Breakpoint_Button, 6, 12, 2, 6, Qt::AlignCenter);
	debugLayout->addWidget(Continue_Button, 8, 12, 2, 6, Qt::AlignCenter);
	debugLayout->addWidget(Step_Button, 10, 12, 2, 6, Qt::AlignCenter);
	debugLayout->addWidget(Next_Button, 12, 12, 2, 6, Qt::AlignCenter);
	debugLayout->addWidget(Inspect_Button, 14, 12, 2, 6, Qt::AlignCenter);
	debugLayout->addWidget(Quit_Button, 16, 12, 2, 6, Qt::AlignCenter);
	debugWindow->setLayout(debugLayout);
	debugWindow->setWindowTitle("Debugger Window");


	//components of the values window
	valuesWindow = new QWidget();
	valuesWindow->setWindowTitle("Values Window");
	valuesLayout = new QGridLayout();
	scrolly2 = new QListWidget();
	valueUpdate = new QPushButton("Update Values");
	connect(valueUpdate, SIGNAL(clicked()), this, SLOT(updateVals()));
	valueHide = new QPushButton("Hide");
	connect(valueHide, SIGNAL(clicked()), this, SLOT(hidev()));
	nameA = new QRadioButton("Name (Ascending)", this);
	nameD = new QRadioButton("Name (Descending)", this);
	valueI= new QRadioButton("Value (Increasing)", this);
	valueD= new QRadioButton("Value (Decreasing)", this);
	valuesLayout->addWidget(nameA, 0,0,2,2, Qt::AlignLeft);
	valuesLayout->addWidget(nameD, 4,0,2,2, Qt::AlignLeft);
	valuesLayout->addWidget(valueI, 8,0,2,2, Qt::AlignLeft);
	valuesLayout->addWidget(valueD, 12,0,2,2, Qt::AlignLeft);
	valuesLayout->addWidget(scrolly2, 16,0,20,10, Qt::AlignCenter);
	valuesLayout->addWidget(valueUpdate, 38,0,4,10, Qt::AlignLeft);
	valuesLayout->addWidget(valueHide, 38,0,4,10, Qt::AlignRight);
	valuesWindow->setLayout(valuesLayout);

	high = true; //used later for highlighting coordination
}

//updates values in the values window
void MainWindow::updateVals()
{
	scrolly2->clear();
	vector<string> inames;
	vector<int> ivalues;
	vector< std::pair<string, int> > pair_vector;
	map<string, int> myMap = base->getList();
	string one;
	string two;
	string line;
	QString qline;
	map<string, int>::iterator it;
	for(it = myMap.begin( ); it != myMap.end( ); ++it)
	{
		one = it->first;
		stringstream ss;
		ss << it->second;
		two = ss.str();
		inames.push_back(one);
		int dos = atoi(two.c_str());
		ivalues.push_back(dos);
		pair_vector.push_back(make_pair(one,dos));
	}


	//sort the vector based on the radio buttons
	//load the sorted vector values into the scrollbox

	if(nameA->isChecked())
	{
		LowToHigh<string> comp;
		mergeSort(inames, comp);
		//rematch the two vectors
		for(unsigned int j=0; j<inames.size(); j++)
		{
			for(unsigned int k=0; k<pair_vector.size(); k++)
			{
				if(inames[j] == pair_vector[k].first)
				{
					ivalues[j] = pair_vector[k].second;
				}
			}
		}
	}
	if(nameD->isChecked())
	{
		HighToLow<string> comp;
		mergeSort(inames, comp);
		//rematch the two vectors
		for(unsigned int j=0; j<inames.size(); j++)
		{
			for(unsigned int k=0; k<pair_vector.size(); k++)
			{
				if(inames[j] == pair_vector[k].first)
				{
					ivalues[j] = pair_vector[k].second;
				}
			}
		}
	}
	if(valueI->isChecked())
	{
		LowToHigh<int> comp;
		mergeSort(ivalues, comp);
		//rematch the two vectors
		for(unsigned int j=0; j<ivalues.size(); j++)
		{
			for(unsigned int k=0; k<pair_vector.size(); k++)
			{
				if(ivalues[j] == (pair_vector[k]).second)
				{
					if(!visitedContains(j) && !visited2Contains(k))
					{
						inames[j] = (pair_vector[k]).first;
						visited.push_back(j);
						visited2.push_back(k);
					}
				}
			}
		}
		visited.clear();
		visited2.clear();
	}
	if(valueD->isChecked())
	{
		HighToLow<int> comp;
		mergeSort(ivalues, comp);
		//rematch the two vectors
		for(unsigned int j=0; j<ivalues.size(); j++)
		{
			for(unsigned int k=0; k<pair_vector.size(); k++)
			{
				if(ivalues[j] == (pair_vector[k]).second)
				{
					if(!visitedContains(j) && !visited2Contains(k))
					{
						inames[j] = (pair_vector[k]).first;
						visited.push_back(j);
						visited2.push_back(k);
					}
				}
			}
		}
		visited.clear();
		visited2.clear();
	}

	//add the items to the scrollbox
	for(unsigned int i=0; i<inames.size(); i++)
	{
		stringstream ss;
		ss << ivalues[i];
		string segundo = ss.str();
		line = inames[i] + " " + segundo;
		qline = QString::fromStdString(line);
		scrolly2->addItem(qline);
	}
}

//sets up the debugger window's scrollbox
//also begins the interpreter
void MainWindow::setScrolly(std::ifstream& infile)
{
	scrolly->clear();
	scrollySet = true;
	linecounter = 0;
	string line;
	QString qline;
	program.push_back(NULL);
	while(!infile.eof())
	{
		//push in all lines
		getline(infile, line);
		qline = QString::fromStdString(line);
		scrolly->addItem(qline);
		scrolly->item(linecounter)->setForeground(Qt::black);
		program.push_back(parseLine(line));
		linecounter++;
	}
	int numStatements = program.size();
	base = new ProgramState(numStatements);
	scrolly->item(0)->setBackground(Qt::yellow);
}

//hides the values window
void MainWindow::hidev()
{
	valuesWindow->hide();
}

//A breakpoint button which, when pressed, adds a breakpoint to the
//selected line of code. There should be some kind of visual cue to
//let the user know which lines currently have breakpoints.
void MainWindow::addBP()
{
	if(scrolly->selectedItems().size() != 0) {
		if(brContains(scrolly->currentRow()))
		{
			Break_Lines.erase(std::remove(Break_Lines.begin(), Break_Lines.end(), (scrolly->currentRow())), Break_Lines.end());
			scrolly->item(scrolly->currentRow())->setForeground(Qt::black); // sets black text
		}
		else
		{
			Break_Lines.push_back(scrolly->currentRow());
			scrolly->item(scrolly->currentRow())->setForeground(Qt::red); // sets red text
		}
	}
}

//A continue button. This causes the program to continue to
//interpret the program until it reaches a breakpoint, 
//at which point it should wait for further user input.
void MainWindow::cont()
{
	//bool ran = false;
	step();
	while((!brContains(base->programCounter-1)) && !(base->shouldEnd()) && !stop)
	{
		step();
		//ran = true;
	}
	if(base->shouldEnd() || stop)
	{
		resetAll();
	}
}

//A step button. When the step button is pushed,
//the interpreter should advance one line of code,
//and then wait for further user input.
void MainWindow::step()
{
	stop = false;
	if(!base->shouldEnd())
	{
		//Execute statements in order
		if(high)
		{
			scrolly->item(0)->setBackground(Qt::yellow);
			high = false;
		}
		else
		{
			scrolly->item(0)->setBackground(Qt::white);
		}
		scrolly->item(base->programCounter-1)->setBackground(Qt::white);
		try{
			(program[base->programCounter])->execute(base, cout);
			if(!base->shouldEnd())
			{
				scrolly->item(base->programCounter-1)->setBackground(Qt::yellow);
			}
			else
			{
				high = true;
			}
		}
		catch (overflow_error e1){ // divide by 0 error
			// Set message box text values
			errorBox->setWindowTitle("Error");
			errorBox->setText("Failed to Execute Line      ");
			errorBox->setInformativeText(+e1.what());
			stop = true;
			resetAll();
			errorBox->show();
		}
		catch (runtime_error e1){ // illogical jump error
			// Set message box text values
			errorBox->setWindowTitle("Error");
			errorBox->setText("Failed to Execute Line      ");
			errorBox->setInformativeText(+e1.what());
			stop = true;
			resetAll();
			errorBox->show();
		}
		catch (...){ // any other errors
			// Set message box text values
			errorBox->setWindowTitle("Error");
			errorBox->setText("Failed to Execute Line      ");
			errorBox->setInformativeText("Illegal Instruction");
			errorBox->show();
			stop = true;
			resetAll();
		}
	}
	else
	{
		//start the debugger window over again
		resetAll();
		scrolly->item(0)->setBackground(Qt::yellow);
	}
}

//method to restart the debugger window
void MainWindow::resetAll()
{
	Gosub_Lines.clear();
	Return_Lines.clear();
	visited.clear();
	visited2.clear();
	program.clear();
	delete base;
	load();
	for(unsigned int i=0; i<Break_Lines.size(); i++)
	{
		scrolly->item(Break_Lines[i])->setForeground(Qt::red);
	}
}


//A next button. This operates exactly like a step,
//except that if it is on a GOSUB line, then it should
//interpret until it returns from this GOSUB call,
//or until it reaches a breakpoint (whichever happens first).
void MainWindow::next()
{
	if(base->shouldEnd())
	{
		resetAll();
	}
		stop = false;
		if(!gsContains(base->programCounter-1) && (!brContains(base->programCounter-1)))
		{
			step();
		}
		else
		{
			bool stepped = false;
			//step until reached return line or until breakpoint reached
			while(!reContains(base->programCounter-1) && !brContains(base->programCounter-1) && !base->shouldEnd() && !stop)
			{
				step();
				stepped = true;
			}
			if(!stepped && !base->shouldEnd() && brContains(base->programCounter-1))
			{
				step();
			}
		}
}

//An inspect button. When pressed, this should show the Values Window.
void MainWindow::inspect()
{
	updateVals();
	valuesWindow->show();
}


//returns true if the breakpoint vector includes the int x
bool MainWindow::brContains(int x)
{
	if(std::find(Break_Lines.begin(), Break_Lines.end(), x) != Break_Lines.end()) {
	    /* Break_Lines contains x */
	    return true;
	} else {
	    /* Break_Lines does not contain x */
	    return false;
	}
}

//returns true if the visited vector includes the int x
bool MainWindow::visitedContains(int x)
{
	if(std::find(visited.begin(), visited.end(), x) != visited.end()) {
	    /* visited contains x */
	    return true;
	} else {
	    /* visited does not contain x */
	    return false;
	}
}

//returns true if the visited2 vector includes the int x
bool MainWindow::visited2Contains(int x)
{
	if(std::find(visited2.begin(), visited2.end(), x) != visited2.end()) {
	    /* visited2 contains x */
	    return true;
	} else {
	    /* visited2 does not contain x */
	    return false;
	}
}

//returns true if the return lines vector includes the int x
bool MainWindow::reContains(int x)
{
	if(std::find(Return_Lines.begin(), Return_Lines.end(), x) != Return_Lines.end()) {
	    /* Return_Lines contains x */
	    return true;
	} else {
	    /* Return_Lines does not contain x */
	    return false;
	}
}

//returns true if the gosub lines vector includes the int x
bool MainWindow::gsContains(int x)
{
	if(std::find(Gosub_Lines.begin(),Gosub_Lines.end(), x) != Gosub_Lines.end()) {
	    /* Gosub_Lines contains x */
	    return true;
	} else {
	    /* Gosub_Lines does not contain x */
	    return false;
	}
}

//loads the file from the user input
void MainWindow::load()
{
	text = edit->text();
 	std::string filename = text.toStdString();
    std::ifstream infile(filename.c_str());
    //check to see if document was loaded
 	if(infile)
 	{
     	resultLabel->setText("Loaded "+text+".\n* Red indicates a "+ 
     		"breakpoint.\n* Yellow indicates hault line (not yet interpreted).");
     	debugWindow->show();
     	this->hide();
     	setScrolly(infile);
 	}
 	else // failed to load
 	{
 		// Set message box text values
		errorBox->setWindowTitle("Error");
		errorBox->setText("The File Failed to Load");
		errorBox->setInformativeText("Please Enter a New File Name or Quit");
		// Add buttons to message box
		errorBox->setStandardButtons(QMessageBox::Ok);
		errorBox->setDefaultButton(QMessageBox::Ok);
 		errorBox->show();
 	}
}

//A quit button. When pressed, the program gracefully terminates.
void MainWindow::quit()
{
	//method to quit entire application
	QApplication::exit();
}

MainWindow::~MainWindow()
{
	//delete all dynamically allocated memory
	delete debugLayout;
	delete resultLabel;
	delete Breakpoint_Button;
	delete Continue_Button;
	delete Step_Button;
	delete Next_Button;
	delete Inspect_Button;
	delete Quit_Button;
	delete scrolly;
	delete errorBox;
	delete loadLayout;
	delete debugWindow;
	delete loadButton;
	delete loadQuitButton;
	delete edit;
	delete valuesLayout;
	delete scrolly2;
	delete valueUpdate;
	delete valueHide;
	delete nameA;
	delete nameD;
	delete valueI;
	delete valueD;
	delete valuesWindow;
	if(scrollySet)
	{
		delete base;
		// MUST DELETE ALL STATEMENTS
		for(unsigned int i=1; i<program.size(); i++)
		{
			delete program[i];
		}
	}
}

//parseline function exactly as it was in Facile
Statement * MainWindow::parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string type;
	string var;
	int val;

	ss << line;
	ss >> type;
	
	if ( type == "LET" ) // LET *var* *int* | Change the value of variable *var* to the integer *int*
	{
		ss >> var;
		ss >> val;
		// Note:  Because the project spec states that we can assume the file
		//	  contains a syntactically legal Facile program, we know that
		//	  any line that begins with "LET" will be followed by a space
		//	  and then a variable and then an integer value.
		statement = new LetStatement(var, val);
	}

	else if ( type == "PRINT" ) // PRINT *var* | Print the value of variable *var* to output
	{
		ss >> var;
		statement = new PrintStatement(var);
	}

	else if ( type == "ADD" ) //ADD *var* *p*| Adds *p* to the value of the variable *var*, where *p* is an int or variable.
	{
		ss >> var;
		string var2;
		ss >> var2;
		if(!isNum(var2))
		{
			statement = new AddStatement(var, var2);
		}
		else
		{
			val = atoi(var2.c_str());
			statement = new AddStatement(var, val);
		}
	}

	else if ( type == "SUB" ) //SUB *var* *p*| Subtracts *p* from  the value of the variable *var*, where *p* is an int or variable.
	{
		ss >> var;
		string var2;
		ss >> var2;
		if(!isNum(var2))
		{
			statement = new SubStatement(var, var2);
		}
		else
		{
			val = atoi(var2.c_str());
			statement = new SubStatement(var, val);
		}
	}

	else if (type == "MULT" ) // MULT *var* *p*   | Multiplies the value of the variable *var* by the integer or variable *p*
	{
		ss >> var;
		string var2;
		ss >> var2;
		if(!isNum(var2))
		{
			statement = new MultStatement(var, var2);
		}
		else
		{
			val = atoi(var2.c_str());
			statement = new MultStatement(var, val);
		}
	}

	else if (type == "DIV" ) // DIV *var* *p* | Divides the value of the variable *var* by the integer or variable *p*
	{
		ss >> var;
		string var2;
		ss >> var2;
		if(!isNum(var2))
		{
			statement = new DivStatement(var, var2);
		}
		else
		{
			val = atoi(var2.c_str());
			statement = new DivStatement(var, val);
		}
	}

	else if (type == "GOTO") //GOTO *linenum* | Jumps execution of the program to the line numbered *linenum*
	{
		ss >> val;
		statement = new GotoStatement(val);
	}

	else if (type == "IF") // IF *var* *op* | Compares the value of the variable *var* to the integer *int*
					  // *int* THEN    | via the operator *op* (<, <=, >, >=, =, <>), and jumps
					  //*linenum*      | execution of the program to line *linenum* if true.
	{
		string var2;
		string var3;
		int val2;
		ss >> var;
		ss >> var2;
		ss >> val;
		ss >> var3;
		ss >> val2;
		statement = new IfStatement(var, var2, val, val2);
	}

	else if (type == "END") // END | Immediately terminates the program.
	{
		statement = new EndStatement();
	}

	else if (type == "RETURN") // RETURN | Jumps back to line following most recent GOSUB statement
	{
		statement = new ReturnStatement();
		Return_Lines.push_back(linecounter);
		//cout<<"RETURN ON: "<<linecounter<<endl;
	}

	else if (type == "GOSUB") // GOSUB | Same as GOTO except execution will jump back after RETURN statement.
	{
		ss >> val;
		statement = new GosubStatement(val);
		Gosub_Lines.push_back(linecounter);
		//cout<<"GOSUB ON: "<<linecounter<<endl;
	}

	else if (type == "PRINTALL") // PRINTALL  | Prints the value of all used variables to output, one per line.
	{
		statement = new PrintAllStatement();
	}

	else if (type == ".") // .  | Placed at the end of the program, and behaves like an END statement.
	{
		statement = new EndStatement();
	}
	else // theoretically should not be reached - to handle uninitialized warning
	{
		statement = new EndStatement();
	}
	return statement;
}

//returns true if name is a numeric value
bool MainWindow::isNum(string name)
{
	if(name.substr(0,1) == "-")
	{
		return true;
	}
	if(name.substr(0,1) == "0")
	{
		return true;
	}
	if(name.substr(0,1) == "1")
	{
		return true;
	}
	if(name.substr(0,1) == "2")
	{
		return true;
	}
	if(name.substr(0,1) == "3")
	{
		return true;
	}
	if(name.substr(0,1) == "4")
	{
		return true;
	}
	if(name.substr(0,1) == "5")
	{
		return true;
	}
	if(name.substr(0,1) == "6")
	{
		return true;
	}
	if(name.substr(0,1) == "7")
	{
		return true;
	}
	if(name.substr(0,1) == "8")
	{
		return true;
	}
	if(name.substr(0,1) == "9")
	{
		return true;
	}
	return false;
}