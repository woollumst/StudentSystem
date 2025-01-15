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

	// create instance of classRoster
	Roster classRoster;
	// add each student to classRoster
for(string student : studentData){
   classRoster.add(student); //fix?
}

	//TODO

	classRoster.printAll();
	classRoster.printInvalidEmails();

	//loop through classRosterArray and for each element: 
	// classRoster.printAverageDaysInCourse(currentStudent.getStudentID());
	for (int i = 0; i < classRosterArray.size(); i++) {
		classRoster.printAverageDaysInCourse(classRosterArray[i].getStudentID());
	}

	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3"); //should handle error, saying: "Such a student with this ID was not found."

	return 0;
}