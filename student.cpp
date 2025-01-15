#include "student.h"
#include <iostream>

//Constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	*this->daysToCompleteCourse = *daysToCompleteCourse; // fix?
	this->degreeProgram = degreeProgram;
}

//Member Functions
void Student::print() { //Finish print statement
	cout << this->studentID << "\tFirst Name: " << this->firstName << "\tLast Name: " << this->lastName << "\tAge: " << this->age << "\tdaysInCourse: {" << this->daysToCompleteCourse[0] << ", " << this->daysToCompleteCourse[1] << ", " << this->daysToCompleteCourse[2] << "} Degree Program: " << this->degreeProgram << endl;
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
void Student::setDaysToCompleteCourses(int* newDaysToCompleteCourse) {
	*this->daysToCompleteCourse = *newDaysToCompleteCourse; //May need to look into pointers for this
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}