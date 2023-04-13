#include <iostream>
#include <string>
#include <regex>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;


void Roster::parse(string studentData)// Parses each row at a time
{
    std::string::size_type rhs = studentData.find(","); //find comma
    string _studentID = studentData.substr(0, rhs); //extract substring in front of coma
    
    std::string::size_type lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string _firstName = studentData.substr(lhs, rhs - lhs); //Students first name
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string _lastName = studentData.substr(lhs, rhs - lhs); //Students last name
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string _Email = studentData.substr(lhs, rhs - lhs); //Students email
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int _Age = stoi(studentData.substr(lhs, rhs - lhs)); //Students age
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int _daysinCourse0 = stoi(studentData.substr(lhs, rhs - lhs)); //Days in course 1
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int _daysinCourse1 = stoi(studentData.substr(lhs, rhs - lhs)); //Days in course 2
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int _daysinCourse2 = stoi(studentData.substr(lhs, rhs - lhs)); //Days in course 3
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs); //Students Degree Program
    string degreeProgramString = studentData.substr(lhs, rhs - lhs);
    
    DegreeProgram degreeProgram; // Find degree program based on strings name and assigning that variable to the enum Degree Program)
    
    if (degreeProgramString == "SECURITY")
    {
        degreeProgram = SECURITY;
    }
    else if (degreeProgramString == "NETWORK")
    {
        degreeProgram = NETWORK;
    }
    else if (degreeProgramString == "SOFTWARE")
    {
        degreeProgram = SOFTWARE;
        
    }
    else
    {
        degreeProgram = NONE; // Default Degree Progam
    }
    
    add(_studentID, _firstName, _lastName, _Email, _Age, _daysinCourse0, _daysinCourse1, _daysinCourse2, degreeProgram);  // Adds the variables
}

// Code to add the new student data to the Roster
void Roster::add(string _studentID, string _firstName, string _lastName, string _Email, int _Age, int _daysinCourse0, int _daysinCourse1, int _daysinCourse2, DegreeProgram degreeprogram) {

    int days[3] = { _daysinCourse0, _daysinCourse1, _daysinCourse2 }; // Adds all three of the days in each course

    classRosterArray[++lastIndex] = new Student(_studentID, _firstName, _lastName, _Email, _Age, days, degreeprogram);
}

// Code to remove the students ID
void Roster::remove(string _studentID)
{
    bool success = false; // Assumed
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == _studentID) // Find ID
        {
            success = true;
            if (i < students - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[students - 1];
                classRosterArray[students - 1] = temp; // Removes studentID
            }
            Roster::lastIndex--; // Last student cannot be seen
        }
    }
    if (success)
    {
        cout << "This student: " << _studentID << " has been removed from the repository." << std::endl; // Prints to output removed student ID
        this->printAll();
    }
    else cout << "This student: " << _studentID << " was not found." <<std::endl;
}

// Prints each row of data in classRosterArray
void Roster::printAll()
{
    Student::printHeader();
    for (int i = 1; i <= Roster::lastIndex; i++)
    {
        cout << classRosterArray[i]->getID(); cout << '\t';
        cout << "First Name: " << classRosterArray[i]->getfName(); cout << '\t';
        cout << "Last Name: " << classRosterArray[i]->getlName(); cout << '\t';
        cout << "Age: " << classRosterArray[i]->getAge(); cout << '\t';
        cout << "daysInCourse: "<< classRosterArray[i]->getdays()[0]; cout << ", " << classRosterArray[i]->getdays()[1]; cout << ", " << classRosterArray[i]->getdays()[2]; cout << '\t'; // Prints each day
        cout << "Degree Program: " << DegreeProgramString[classRosterArray[i]->getdegreeProgram()] << std::endl;

    }
}

// Prints the average day in the courses
void Roster::printAverageDaysInCourse(string studentID)
{
    
    for (int i = 1; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            int course1, course2, course3; // New variable for each course
            cout << "Student: " << studentID << endl;
            course1 = classRosterArray[i]->getdays()[0]; // stores days in course location 0 into course1 variable
            course2 = classRosterArray[i]->getdays()[1];
            course3 = classRosterArray[i]->getdays()[2];
            int averageDays; // Variable for the average
            averageDays = (course1 + course2 + course3)/ 3.0; // Computes the average by adding them together and dividing by 3.0
            cout << "Average number of Days in each course: " << averageDays << std::endl;
        }
    }
}

// Prints invalid Emails from the student data
void Roster::printInvalidEmails()
{
    cout << "Invalid Emails:" << endl;
    
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string _Email = (classRosterArray[i]->getEmail());
        if ((_Email.find('@') == string::npos) || (_Email.find('.') == string::npos) || (_Email.find(' ') != std::string::npos)) // Email needs an '@' and '.', but no ' '
        {
            any = true; // If any of the above invalid email items are missing print that email
            cout << _Email << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

// Prints the specified degree program that corresponds to the student in studentData
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i]->getdegreeProgram() == degreeProgram) classRosterArray[i] ->print(); // Degree prints and any student with that program declared will be printed
    }
    cout << std::endl;
}

// Prints students that have been destroyed
Roster::~Roster()
{
    cout << "DESTRUCTOR" << std::endl;
    for (int i = 0; i < students; i++)
    {
        cout << "Destroying student" << i + 1 << std::endl;
        //delete classRosterArray[i];  //Deletes all the students
        classRosterArray[i] = nullptr;
    }
}
