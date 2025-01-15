#include "roster.h";

Roster::Roster() {
	
}

// classRosterArray : an array of pointers to hold data from studentDataTable
// parse studentDataTable to create student object for each student in table, populate to classRosterArray

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	Student newStudent = new Student;
}
void Roster::remove(string studentID) {
	
}
void Roster::printAll() {
	// A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
	
}
void Roster::printAverageDaysInCourse(string studentID) {

}
void Roster::printInvalidEmails() {

}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

}