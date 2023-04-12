#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

/* This is my code for Section D of the Performance Assesment. I have created private data which is
* the requirements for D1 of the project and public data which is the requirements for D2 of the project.
*/


class Student {



public:
	const static int courseSize = 3;

private:

	//student variables
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

public:
	Student(); // Parameterless constructor (set values to default)
	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[3], DegreeProgram degreeProgram); // Full constructor
	~Student(); // Destructor


	// Accessors for each variable in D1
	string getID();
	string getfName();
	string getlName();
	string getEmail();
	int getAge();
	int getdaysinCourse();
	DegreeProgram getdegreeProgram();

	// Mutators for each variable in D1
	void setID(string ID);
	void setfName(string fName);
	void setlName(string lName);
	void setEmail(string email);
	void setAge(int Age);
	void setdaysinCourse(int daysInCourse[3]);
	void setdegreeProgram(DegreeProgram dp);

	static void printHeader(); // Header Display

	void print(); // Displays the specific students data through print function

	void printdegree();


};