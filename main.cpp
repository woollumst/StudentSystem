#include <iostream>
#include "roster.h"

using namespace std;

int main() {
	
	const string studentData[] = { //this might go in another file
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Toby,Woollums,twooll10@wgu.edu,27,20,40,30,SOFTWARE"
	};
	
	cout << "Course Name: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "Student ID: 012488334" << endl;
	cout << "Name: Toby Woollums" << endl;

	// studentData->size() is unacceptable, yields bad results
	int size = sizeof(studentData); // F I X
	cout << endl << endl << "Size of array: " << size << endl << endl;
	
// create instance of classRoster
	Roster classRoster(size);

	// add each student to classRoster
	while (studentData[rosterIndex] != null){
		string currStudent = studentData[rosterIndex]; //temp string to hold each student's data
		string studentID, firstName, lastName, email; //temp variables to read into student object
		int age, days1, days2, days3;
		DegreeProgram degreeProgram;

		studentID = currStudent.substr(0, 2);
		currStudent = currStudent.substr(3, currStudent.length() - 3);
		firstName = currStudent.substr(0, currStudent.find(',') - 1);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		lastName = currStudent.substr(0, currStudent.find(',') - 1);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		email = currStudent.substr(0, currStudent.find(',') - 1);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		age = static_cast<int> currStudent.substr(0, currStudent.find(',') - 1);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		//int array
		days1 = static_cast<int> currStudent.substr(0, currStudent.find(',') - 1);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		days2 = static_cast<int> currStudent.substr(0, currStudent.find(',') - 1);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		days3 = static_cast<int> currStudent.substr(0, currStudent.find(',') - 1);
		currStudent = currStudent.substr(currStudent.find(',') + 1, currStudent.length() - (currStudent.find(',') + 1));
		switch (currStudent){
			case ("SOFTWARE"): 
				degreeProgram = SOFTWARE;
			case ("NETWORK"):
				degreeProgram = NETWORK;
			case ("SECURITY"):
				degreeProgram = SECURITY;
		}

		classRoster.add(studentID, firstName, lastName, email, age, days1, days2, days3, degreeProgram); //fix?
	}
	
	//classRoster.printAll();
	//classRoster.printInvalidEmails();
	/*
	//loop through classRosterArray and for each element: 
	// classRoster.printAverageDaysInCourse(currentStudent.getStudentID());
	for (int i = 0; i < size; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i].getStudentID());
	}

	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3"); //should handle error, saying: "Such a student with this ID was not found."
	*/
	//delete[] classRoster.classRosterArray; // BROKEN?
	
	return 0;
}