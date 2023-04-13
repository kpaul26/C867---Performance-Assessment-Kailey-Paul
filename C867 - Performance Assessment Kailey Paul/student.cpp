#include <iostream>
#include "student.h"
using namespace std;

Student::Student() {

    // Default values for each string and Int
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->studentAge = 0;
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
    this->degreeProgram;
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[3], DegreeProgram degreeProgram)
{
    // Parameterless constructor
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->studentAge = studentAge;
    this->daysInCourse[0] = daysInCourse[0];
    this->daysInCourse[1] = daysInCourse[1];
    this->daysInCourse[2] = daysInCourse[2];
    this->degreeProgram = degreeProgram;
}
   
Student::~Student() {} // Destructor

// Accessors defined
string Student::getID() { return this->studentID; }
string Student::getfName() { return this->firstName; }
string Student::getlName() { return this->lastName; }
string Student::getEmail() { return this->emailAddress; }
int Student::getAge() { return this->studentAge; }
int Student::getdaysinCourse() {return this->daysInCourse[0,1,2];}
DegreeProgram Student::getdegreeProgram() { return this->degreeProgram; }



void Student::setID(string ID) { this->studentID = ID; }
void Student::setfName(string fName) { this->firstName = fName; }
void Student::setlName(string lName) { this->lastName = lName; }
void Student::setEmail(string Email) { this->emailAddress; }
void Student::setAge(int Age) { this->studentAge; }

// Add the days together to get the total
void Student::setdaysinCourse(int daysInCourse[3]) {
    for (int i = 0; i < 3; i++) 
        this->daysInCourse[0] = daysInCourse[0];
        this->daysInCourse[1] = daysInCourse[1];
        this->daysInCourse[2] = daysInCourse[2];
}

void Student::setdegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }


// Printing the data

void Student::printHeader()
{
    cout << "Student Information:\n";

    return;
}

void Student::print() {
    cout << "Student ID: "<< this->getID() << '\t';
    cout << "First Name: " << this->getfName() << '\t';
    cout << "Last Name: " << this->getlName() << '\t';
    cout << "Email: " << this->getEmail() << '\t';
    cout << "Student's Age: " << this->getAge() << '\t';
    cout << "Days in Course: " << this->daysInCourse[0] << ", " << this->daysInCourse[1] << ", " << this->daysInCourse[2] << '\t';

    return;
}

void Student::printdegree() {
    string _degree;
    if (degreeProgram == SECURITY) {
        _degree = "SECURITY";
    }
    else if (degreeProgram == NETWORK) {
        _degree = "NETWORK";
    }
    else if (degreeProgram == SOFTWARE) {
        _degree = "SOFTWARE";
    }
    
    cout << "Degree Program: " << _degree;

        return;
}
