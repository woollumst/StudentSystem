#include "roster.h";

Roster::Roster(int size){
   Student* classRosterArray = new Student[size];
   classSize = size;
   rosterIndex = 0;
}

Roster::~Roster(){ // Destructor
    cout << "Roster destructor called." << endl;
}

// Add a Student to the classRosterArray. Parsed from Main
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
        if(classRosterArray[i].getStudentID() == studentID){ // Search by Student ID
            cout << "Student " << studentID << " found for deletion..." << endl << endl;
            for (int j = i; j < classSize-1; j++) {
                classRosterArray[j] = classRosterArray[j + 1]; // Moving other elements up
            }
            classSize--; // "Deleting" last element
            return;
      }
   }
   cout << "Student " << studentID << " was not found." << endl << endl;
}

void Roster::printAll() {
    cout << "All Students: " << endl;
    for (int i = 0; i < classSize; i++) {
        classRosterArray[i].print(); // A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security.
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {//find student from student ID, print average days in courses 
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
    } else {
        cout << "Student not found for average." << endl;
    }
}

void Roster::printInvalidEmails() { // Email validation. should have '@' and '.' but no spaces
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
      if(!((emailAt && emailPeriod) && !emailSpace)) // If has spaces or no '@' or no '.'
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