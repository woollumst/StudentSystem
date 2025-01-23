#include <iostream>
#include "roster.h"

using namespace std;

const string studentData[] = { //this might go in another file
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Toby,Woollums,twooll10@wgu.edu,27,20,40,30,SOFTWARE"
};


int convertToInt(string inputText) {
	return ((inputText[0] - '0') * 10) + (inputText[1] - '0');
}

void parseStudents(int size, Roster classRoster) {
	for (int i = 0; i < size; i++) {
		string currStudent = studentData[i]; //temp string to hold each student's data
		string studentID, firstName, lastName, email; //temp variables to read into student object
		DegreeProgram degreeProgram = SECURITY;

		int age, days1, days2, days3;

		studentID = currStudent.substr(0, 2);
		currStudent = currStudent.substr(3, currStudent.length() - 3);
		firstName = currStudent.substr(0, currStudent.find(','));
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		lastName = currStudent.substr(0, currStudent.find(','));
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		email = currStudent.substr(0, currStudent.find(','));
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		age = convertToInt(currStudent);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		days1 = convertToInt(currStudent);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		days2 = convertToInt(currStudent);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		days3 = convertToInt(currStudent);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		if (currStudent == "SOFTWARE")
			degreeProgram = SOFTWARE;
		else if (currStudent == "NETWORK")
			degreeProgram = NETWORK;
		classRoster.add(studentID, firstName, lastName, email, age, days1, days2, days3, degreeProgram); //fix?
	}
}

int main() {
	cout << "Course Name: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "Student ID: 012488334" << endl;
	cout << "Name: Toby Woollums" << endl << endl;
	int size = 5;

	// create instance of classRoster
	Roster classRoster(size);

	// Parse and add each student to classRoster
	parseStudents(size, classRoster);
	classRoster.printAll();
	cout << endl;
	classRoster.printInvalidEmails();
	cout << endl;
	
	for (int i = 0; i < size; i++) { // Printing each student's average days in course
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i].getStudentID());
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3"); //should handle error, saying: "Such a student with this ID was not found."
	
	//delete[] classRoster.classRosterArray; // Deallocate student objects and array
	
	return 0;
}