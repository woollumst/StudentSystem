#pragma once
#include "degree.h"
#include <string>

using namespace std;

class Student {
	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int daysToCompleteCourse[3];
		DegreeProgram degreeProgram;

		//Constructors
	public:
		Student(string studentID, string firstName, string lastName, string email, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram);
		Student();
		~Student();

		//Member Functions
	public:
		void print();

		//Getters
	public:
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		int* getDaysToCompleteCourses();
		DegreeProgram getDegreeProgram();

		//Setters
	public:
		void setStudentID(string newID);
		void setFirstName(string name);
		void setLastName(string name);
		void setEmail(string newEmail);
		void setAge(int newAge);
		void setDaysToCompleteCourses(int* newDaysToCompleteCourse); // Fix?
		void setDegreeProgram(DegreeProgram degreeProgram);
};