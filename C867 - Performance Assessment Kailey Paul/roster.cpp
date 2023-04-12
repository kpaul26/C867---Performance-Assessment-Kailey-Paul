#pragma once
#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;


void Roster::parse(string studentData)// Parses each row at a time
{


    int rhs = studentData.find(","); //find comma
    string _studentID = studentData.substr(0, rhs); //extract substring in front of coma

    int lhs = rhs + 1;
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
    int _Age = stod(studentData.substr(lhs, rhs - lhs)); //Students age

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int _daysinCourse0 = stod(studentData.substr(lhs, rhs - lhs)); //Days in course 1

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int _daysinCourse1 = stod(studentData.substr(lhs, rhs - lhs)); //Days in course 2

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int _daysinCourse2 = stod(studentData.substr(lhs, rhs - lhs)); //Days in course 3

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs); //Students Degree Program
    string degreeprogram = studentData.substr(lhs, rhs - lhs);
    
    if (studentData.at(55) == 'S')
    {
        degreeprogram = SECURITY;
    }
    else if (studentData.at(62) == 'N')
    {
        degreeprogram = NETWORK;
    }
    else if (studentData.at(52) == 'S')
    {
        degreeprogram = SOFTWARE;

    }

}

// Code to
void Roster::add(string _studentID, string _firstName, string _lastName, string _Email, int _Age, int _daysinCourse0, int _daysinCourse1, int _daysinCourse2, DegreeProgram degreeprogram) {

    int days[3] = { _daysinCourse0, _daysinCourse1, _daysinCourse2 };

    classRosterArray[++lastIndex] = new Student(_studentID, _firstName, _lastName, _Email, _Age, days, degreeprogram);
}

// Code to remove the students ID
void Roster::remove(string _studentID)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == _studentID)
        {
            success = true;
            if (i < students - 1)
            {
                
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[students - 1];
                classRosterArray[students - 1] = temp;
            }
            Roster::lastIndex--; // Last student cannot be seen
        }
    }
    if (success)
    {
        cout << "This student: " << _studentID << " has been removed from the repository." << std::endl;
        this->printAll();
    }
    else cout << "This student: " << _studentID << " was not found." <<std::endl;
}


void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        cout << classRosterArray[i]->getID(); cout << '\t';
        cout << "First Name: " << classRosterArray[i]->getfName(); cout << '\t';
        cout << "Last Name: " << classRosterArray[i]->getlName(); cout << '\t';
        cout << "Age: " << classRosterArray[i]->getAge(); cout << '\t';
        cout << "daysInCourse: " << classRosterArray[i]->getdaysinCourse(); cout << '\t';
        cout << "Degree Program: " << DegreeProgramString[classRosterArray[i]->getdegreeProgram()] << std::endl;

    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID() == studentID)
        {
            cout << "Student: " << studentID << endl;
            cout << "Average number of days in the three courses: " << (classRosterArray[i]->getdaysinCourse() + classRosterArray[i]->getdaysinCourse() + classRosterArray[i]->getdaysinCourse()) / 3.0 << std::endl;
        }
    }
}

void Roster::printInvalidEmails()
{
    cout << "Invalid Emails:" << endl;
    
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string _Email = (classRosterArray[i]->getEmail());
        if ((_Email.find(' ') == string::npos) || (_Email.find('@') == string::npos) || (_Email.find('.') == string::npos))
        {
            any = true;
            cout << _Email << ": " << classRosterArray[i]->getEmail() << std::endl;
        }
    }
    if (!any) cout << "NONE" << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (Roster::classRosterArray[i]->getdegreeProgram() == degreeProgram) classRosterArray[i] ->print();
    }
    cout << std::endl;
}

Roster::~Roster()
{
    cout << "DESTRUCTOR" << std::endl;
    for (int i = 0; i < students; i++)
    {
        cout << "Destroying student" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
