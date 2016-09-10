//mainwindow.h

#include "lib/Statement.h"
#include "lib/LetStatement.h"
#include "lib/PrintStatement.h"
#include "lib/EndStatement.h"
#include "lib/PrintAllStatement.h"
#include "lib/AddStatement.h"
#include "lib/SubStatement.h"
#include "lib/MultStatement.h"
#include "lib/DivStatement.h"
#include "lib/GotoStatement.h"
#include "lib/IfStatement.h"
#include "lib/GosubStatement.h"
#include "lib/ReturnStatement.h"
#include "../Part3/msort.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QApplication>
#include <QString>
#include <QListWidget>
#include <QListWidgetItem>
#include <QRadioButton>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream> 
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include <algorithm>


class MainWindow : public QWidget
{
	Q_OBJECT
public:
	MainWindow();
	~MainWindow();

	// parseProgram() takes a filename as a parameter, opens and reads the
	// contents of the file, and returns an vector of pointers to Statement.
	void parseProgram(std::istream& inf, std::vector<Statement *> & program);

	// parseLine() takes a line from the input file and returns a Statement
	// pointer of the appropriate type.  This will be a handy method to call
	// within your parseProgram() method.
	Statement * parseLine(std::string line);

	// interpretProgram() reads a program from the given input stream
	// and interprets it, writing any output to the given output stream.
	// Note:  you are required to implement this function!
	void interpretProgram(std::istream& inf, std::ostream& outf);

private slots:
	void load(); //loads document from user input
	void quit(); //quits the application
	void addBP(); //adds a breakpoint
	void cont(); //continues
	void step(); //steps
	void next(); //nexts
	void inspect(); //opens the values window
	void hidev(); //hides the values window
	void updateVals(); //updates the values window

private:
	QGridLayout* debugLayout;
	QVBoxLayout* loadLayout;
	QWidget* debugWindow;
	QPushButton* loadButton;
	QPushButton* loadQuitButton;
	QMessageBox* errorBox;
	QLabel* resultLabel;
	QLineEdit* edit;
	QListWidget* scrolly;

	QWidget* valuesWindow;
	QGridLayout* valuesLayout;
	QListWidget* scrolly2;
	QPushButton* valueUpdate;
	QPushButton* valueHide;
	QRadioButton* nameA;
	QRadioButton* nameD;
	QRadioButton* valueI;
	QRadioButton* valueD;

	QPushButton* Breakpoint_Button;
	QPushButton* Continue_Button;
	QPushButton* Step_Button;
	QPushButton* Next_Button;
	QPushButton* Inspect_Button;
	QPushButton* Quit_Button;
	std::vector<int> Break_Lines;
	std::vector<int> Gosub_Lines;
	std::vector<int> Return_Lines;
	std::vector<int> visited;
	std::vector<int> visited2;
	std::vector<Statement *> program;
	ProgramState* base;

    QString text;
    bool ok;
    bool scrollySet;
    bool stop;
    bool high;
    int linecounter;

    void setScrolly(std::ifstream& infile);
    //returns true if name is a numeric value
	bool isNum(std::string name);
	//returns true if the breakpoint vector includes the int x
	bool brContains(int x);
	//returns true if the return line vector includes the int x
	bool reContains(int x);
	//returns true if the gosub vector includes the int x
	bool gsContains(int x);
	//returns true if the visited vector includes the int x
	bool visitedContains(int x);
	//returns true if the visited2 vector includes the int x
	bool visited2Contains(int x);
	//resets the state of the entire debug window
	void resetAll();
};
