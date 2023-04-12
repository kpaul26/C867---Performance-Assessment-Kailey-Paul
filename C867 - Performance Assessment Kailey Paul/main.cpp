#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <string> //For string use in program
using namespace std;

/* Main function for creating ....

*/

int main() {

    cout << "C867 Scripting and Programming - Applications\n" << "Programming language = C++\n" << "Name: Kailey Paul\n" << "Student ID: 010366202" << endl; //Class name, programming language, Name, and my student ID number

    
    const int students = 5;
    Roster roster;
    
    for(int i = 0; i < students; i++) roster.parse(studentData[i]);
    cout << "StudentData Table: " << std::endl;
    roster.printAll();
    cout << std::endl;
  
    roster.printInvalidEmails();
    

        for (int i = 0; i < students; i++) {

            roster.printAverageDaysInCourse(roster.classRosterArray[i]->getID());
        }
    
    for (int i = 0; i < 3; i++)
    {
        cout << "Displaying by degree program(software): " << DegreeProgramString[i] << std::endl;
        roster.printByDegreeProgram(SOFTWARE);
        cout << std::endl;
    }
    

    roster.remove("A3");
    cout << std::endl;


    roster.remove("A3");
    cout << std::endl;
    
    system("pause");

    return 0;
}

