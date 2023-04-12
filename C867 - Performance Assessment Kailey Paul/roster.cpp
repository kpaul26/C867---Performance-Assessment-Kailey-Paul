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
	if (studentData.at(55) == 'S') {
		degreeprogram = SECURITY;
	}
	else if (studentData.at(62) == 'N') {
		degreeprogram = NETWORK;
	}
	else if (studentData.at(52) == 'S') {
		degreeprogram = SOFTWARE;

	}



}


void Roster::add(string _studentID, string _firstName, string _lastName, string _Email, int _Age, int _daysinCourse0, int _daysinCourse1, int _daysinCourse2, DegreeProgram degreeprogram) {

	int days[3] = { _daysinCourse0, _daysinCourse1, _daysinCourse2 };

	classRosterArray[++lastIndex] = new Student(_studentID, _firstName, _lastName, _Email, _Age, days, degreeprogram);
}

void Roster::remove(string _studentID) {
	bool IDfound;
	for (int i = 0; i < students; i++) {
		if (classRosterArray[i] == nullptr) {
			IDfound = false;
			continue;
		}
		else if (_studentID == classRosterArray[i]->getID()) {
			classRosterArray[i] = nullptr;
			IDfound = true;
			break;
		}
	}
	if (IDfound == false) {
		cout << "Error Message: Student " << _studentID << " not found." << endl;
	}

	return;

}

void Roster::printALL() 
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		cout << classRosterArray[i]->getID(); cout << '\t';
		cout << "First Name: " << classRosterArray[i]->getfName(); cout << '\t';
		cout << "Last Name: " << classRosterArray[i]->getlName(); cout << '\t';
		cout << "Age: " << classRosterArray[i]->getAge(); cout << '\t';
		cout << "daysInCourse: " << classRosterArray[i]->getdaysinCourse(); cout << '\t';
		cout << "Degree Program: " << DegreeProgramString[classRosterArray[i]->getdegreeProgram()] << std::endl;

	}
}
void Roster::printAverageDaysInCourse(string studentID) {

}

void Roster::printInvalidEmails() {

}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

}