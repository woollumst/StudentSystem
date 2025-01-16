#include "roster.h";

Roster::Roster() {
   for(int i = 0; i < classRosterArray.size; i++){
      classRosterArray[i] = null;
   }
}

// classRosterArray : an array of pointers to hold data from studentDataTable
// parse studentDataTable to create student object for each student in table, populate to classRosterArray

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
   
}
void Roster::remove(string studentID) {
	for(int i = 0; i < classRosterArray.size(); i++){
      if(classRosterArray[i]->getStudentID() == studentID){
         delete classRosterArray[i];
         return;
      }
   }
   cout << "Student was not found." << endl;
}
void Roster::printAll() {
	// A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
   for (Student student : Roster){
      student.print();
   }
}
void Roster::printAverageDaysInCourse(string studentID) {
   //find student from student ID, print average days in courses
}
void Roster::printInvalidEmails() {
   //add email validation
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
   for(Student student : Roster){
      if(student.getDegreeProgram() == degreeProgram)
         student.print();
   }
}