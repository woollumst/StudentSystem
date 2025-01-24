#include "roster.h";



Roster::Roster() {
   classRosterArray = new Student[5];
   classSize = 5;
   rosterIndex = 0;
}

Roster::Roster(int size){
   classRosterArray = new Student[size];
   classSize = size;
   rosterIndex = 0;
}

Roster::~Roster(){ // Destructor
    cout << "Roster destructor called." << endl;
    //delete[] classRosterArray; // Deallocate student objects and array
}

// classRosterArray : an array of pointers to hold data from studentDataTable
// parse studentDataTable to create student object for each student in table, populate to classRosterArray
// Add a Student to the classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int courseArr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[rosterIndex].setStudentID(studentID);
    classRosterArray[rosterIndex].setFirstName(firstName);
    classRosterArray[rosterIndex].setLastName(lastName);
    classRosterArray[rosterIndex].setEmail(emailAddress);
    classRosterArray[rosterIndex].setAge(age);
    classRosterArray[rosterIndex].setDaysToCompleteCourses(courseArr);
    classRosterArray[rosterIndex].setDegreeProgram(degreeProgram);
    rosterIndex++;
}

// Remove a Student from classRosterArray
void Roster::remove(string studentID) { // How to remove? 
	for(int i = 0; i < classSize; i++){
      if(classRosterArray[i].getStudentID() == studentID){ // 
          /*delete this->classRosterArray[i];
          classRosterArray[i] = nullptr;*/
          /*classRosterArray[i].setStudentID("0");
          classRosterArray[i].setFirstName(" \t");
          classRosterArray[i].setLastName(" \t");
          classRosterArray[i].setEmail(" ");
          classRosterArray[i].setAge(0);
          classRosterArray[i].setDegreeProgram(SECURITY);
          int temp[] = {0, 0, 0};
          classRosterArray[i].setDaysToCompleteCourses(temp);*/
         return;
      }
   }
   cout << "Student was not found." << endl;
}

void Roster::printAll() {
	// A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
    for (int i = 0; i < classSize; i++) {
      /*if(classRosterArray[i] == nullptr)
         classRosterArray[i].print();*/
   }
}

void Roster::printAverageDaysInCourse(string studentID) {
   //find student from student ID, print average days in courses 
   int average = 0;
   int tempArr[3];
   bool isFound = false;
   
   for(int i = 0; i < classSize; i++){ //find correct student
      if((classRosterArray[i].getStudentID() == studentID) /*&& classRosterArray[i] != nullptr*/){
          isFound = true;
          for(int k = 0; k < 3; k++)
            tempArr[k] = classRosterArray[i].getDaysToCompleteCourses()[k];
          cout << "Student " << classRosterArray[i].getStudentID() << " " << classRosterArray[i].getFirstName() << " has an average of: ";
      }
   }
   
   if (isFound) {
       for (int j = 0; j < 3; j++) {
           average += tempArr[j];
       }
       average /= 3;

       cout << average << endl;
   }
   else {
       cout << "Student not found for average." << endl;
   }
}
void Roster::printInvalidEmails() {
   //add email validation. should have @ and . but no spaces
   for(int i = 0; i < classSize; i++){ // check each student
      //parse email string, maybe booleans?
      bool emailAt = false, emailPeriod = false, emailSpace = false;
      string email = classRosterArray[i].getEmail();
      for(int j = 0; j < email.size(); j++){
         if(email.at(j) == '@')
            emailAt = true;
         else if(email.at(j) == '.')
            emailPeriod = true;
         else if(email.at(j) == ' ')
            emailSpace = true;
      }
      if(!((emailAt && emailPeriod) && !emailSpace))
         cout << "Student " << classRosterArray[i].getStudentID() << " has an invalid email: " << email << endl;
   }
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Students enrolled in the ";
    if (degreeProgram == SECURITY)
        cout << "SECURITY";
    else if (degreeProgram == NETWORK)
        cout << "NETWORK";
    else if (degreeProgram == SOFTWARE)
        cout << "SOFTWARE";
    cout << " Degree Program:" << endl;
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i].getDegreeProgram() == degreeProgram) 
            classRosterArray[i].print();
   }
}