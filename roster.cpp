#include "roster.h";

ClassRoster::ClassRoster() {
	
}

// classRosterArray : an array of pointers to hold data from studentDataTable
// parse studentDataTable to create student object for each student in table, populate to classRosterArray

void ClassRoster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	Student newStudent = new Student;
}
void ClassRoster::remove(string studentID) {
	
}
void ClassRoster::printAll() {
	// A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
	
}
void ClassRoster::printAverageDaysInCourse(string studentID) {

}
void ClassRoster::printInvalidEmails() {

}
void ClassRoster::printByDegreeProgram(DegreeProgram degreeProgram) {

}