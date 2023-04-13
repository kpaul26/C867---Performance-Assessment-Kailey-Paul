#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

/* This is my code for Section D of the Performance Assesment. I have created the first public data which is
* the requirements for D1 of the project and the second public data which is the requirements for D2 of the project.
 Each variable is is created in class student; as seen from it being called at the begining.*/


class Student {



public:
	const static int courseSize = 3;

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
	Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int daysInCourse[2], DegreeProgram degreeProgram); // Full constructor
	~Student(); // Destructor


	// Accessors for each variable in D1. the two first days variable is for calculating average days and second is for finding each day
	string getID();
	string getfName();
	string getlName();
	string getEmail();
	int getAge();
	int* getdays();
    int getdaysInCourse();
	DegreeProgram getdegreeProgram();

	// Mutators for each variable in D1
	void setID(string ID);
	void setfName(string fName);
	void setlName(string lName);
	void setEmail(string email);
	void setAge(int Age);
	void setdaysinCourse(int daysInCourse[2]);
	void setdegreeProgram(DegreeProgram dp);

	static void printHeader(); // Header Display

	void print(); // Displays the specific students data through print function

	void printdegree(); // Displays degree program


};
