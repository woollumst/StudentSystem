#include "roster.h";

Roster::Roster() {
   for(int i = 0; i < 5; i++){
      classRosterArray[i] = null;
   }
   rosterIndex = 0;
}

Roster::~Roster(){ // Destructor
   for(int i = 0; i < 5; i++){
      delete classRosterArray[i];
   }
}

// classRosterArray : an array of pointers to hold data from studentDataTable
// parse studentDataTable to create student object for each student in table, populate to classRosterArray

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
   classRosterArray[rosterIndex] = new Student(studentID, firstName, lastName, emailAddress, age, {daysInCourse1, daysInCourse2, daysInCourse3}, degreeProgram);
   rosterIndex++;
}
void Roster::remove(string studentID) {
	for(int i = 0; i < 5; i++){
      if(classRosterArray[i]->getStudentID() == studentID){
         delete classRosterArray[i];
         rosterIndex--;
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
   int average = 0;
   int tempArr[3];
   for(int i = 0; i < 5; i++){
      if(classRosterArray[i]->getStudentID() == studentID){
         tempArr = &classRosterArray[i]->getDaysInCourses();
      }
   }
   for(int j = 0; j < 3; j++){
      average += tempArr[j];
   }
   average /= 3;
   return average;
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