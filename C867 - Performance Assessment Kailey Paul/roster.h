#pragma once
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

const string studentData[] = {
        "A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
        "A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
        "A3, Jack, Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4, Erin, Black, Erin.black@comcast.net, 22, 50,58,40,SECURITY",
        "A5, Kailey, Paul, kpaul71@wgu.edu, 19, 36, 15, 15, SOFTWARE"
};

class Roster {



public:
    int lastIndex = 0;
    const static int students = 5;
    Student* classRosterArray[students];



public:
    void parse(string row);

    void add(string _studentID,
        string _firstName,
        string _lastName,
        string _Email,
        int _Age,
        int _daysinCourse0,
        int _daysinCourse1,
        int _daysinCourse2,
        DegreeProgram degreeprogram);

    void remove(string _studentID);

    void printAll();

    void printAverageDaysInCourse(string studentID);

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);


    ~Roster();


};
