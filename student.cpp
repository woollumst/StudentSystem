#include "student.h"
#include <iostream>

//Constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram) {
	this->setStudentID(studentID);
	this->setFirstName(firstName);
	this->setLastName(lastName);
	this->setEmail(email);
	this->setAge(age);
	this->setDaysToCompleteCourses(daysToCompleteCourse);
	this->setDegreeProgram(degreeProgram);
} //Student(studentID, firstName, lastName, emailAddress, age, courseArr, degreeProgram)

Student::Student() {
	//default constructor?
	this->studentID = "B0";
	this->firstName = "Unknown";
	this->lastName = "N/A";
	this->email = "N/A";
	this->age = 0;
	this->degreeProgram = SOFTWARE; // default value ?
}

Student::~Student() {
	cout << "Student deconstructor. " << this->studentID << endl;
}

//Member Functions
void Student::print() { //Finish print statement
	cout << this->getStudentID() << "\tFirst Name: " << this->getFirstName() << "\tLast Name: " << this->getLastName() << "\tAge: " << this->getAge() << "\tdaysInCourse: {" << this->getDaysToCompleteCourses()[0] << ", ";
	cout << this->getDaysToCompleteCourses()[1] << ", " << this->getDaysToCompleteCourses()[2] << "} Degree Program: ";
	if (this->getDegreeProgram() == SECURITY)
		cout << "SECURITY";
	else if (this->getDegreeProgram() == NETWORK)
		cout << "NETWORK";
	else if (this->getDegreeProgram() == SOFTWARE)
		cout << "SOFTWARE";
	else
		cout << "INVALID";
	cout << endl;
}

//Accessors / Getters
string Student::getStudentID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmail() {
	return this->email;
}
int Student::getAge() {
	return this->age;
}
int* Student::getDaysToCompleteCourses() {
	return this->daysToCompleteCourse;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

//Mutaters / Setters
void Student::setStudentID(string newID) {
	this->studentID = newID;
}
void Student::setFirstName(string name) {
	this->firstName = name;
}
void Student::setLastName(string name) {
	this->lastName = name;
}
void Student::setEmail(string newEmail) {
	this->email = newEmail;
}
void Student::setAge(int newAge) {
	this->age = newAge;
}
void Student::setDaysToCompleteCourses(int newDaysToCompleteCourse[]) {
	this->daysToCompleteCourse[0] = newDaysToCompleteCourse[0]; //May need to look into pointers for this
	this->daysToCompleteCourse[1] = newDaysToCompleteCourse[1];
	this->daysToCompleteCourse[2] = newDaysToCompleteCourse[2];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}