#pragma once
#include "degree.h"
#include "student.h"
using namespace std;

class Roster {
	// classRosterArray : an array of pointers to hold data from studentDataTable
	
	Student* classRosterArray; // ?? Prob needs work. Pointer array?
	int rosterIndex;
	
	// parse studentDataTable to create student object for each student in table, populate to classRosterArray


public:
	Roster();
	Roster(int size);
	~Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll(); // A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
};