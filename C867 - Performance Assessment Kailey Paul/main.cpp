#include <iostream>
#include <string> //string use
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;

/* Main function for iniating the functions from the other files in order and building the output wanted for the student data.
 I have ordered each step based on the requirements for each step in the Performance Assesment.
*/


int main() {

    cout << "C867 Scripting and Programming - Applications\n" << "Programming language = C++\n" << "Name: Kailey Paul\n" << "Student ID: 010366202" << endl; //Class name, programming language, Name, and my student ID number

    
    const int students = 5;
    Roster roster; // Calls Rooster roster class
    
    for (int i = 0; i < students; i++) roster.parse(studentData[i]); // Structures and seperate the data to be able to access and print
    cout << "\nStudentData Table: " << std::endl;
    
    roster.printAll(); // Prints the student data to output neatly
    cout << std::endl;
  
    roster.printInvalidEmails(); // Finds emails that are invalid and prints them to output
    
    cout << "\nEach students Average days:" << endl;
        for (int i = 0; i < students; i++) // Computes the average days each student spends in the courses
        {
            roster.printAverageDaysInCourse(roster.classRosterArray[i]->getID()); // Pulls student ID and the days they are in the class/3. Then prints both.
            cout << endl;
        }
    cout << endl;
    
    for (int i = 2; i < 3; i++) // Finds Software
    {
        cout << "Displaying by degree program: " << DegreeProgramString[i] << std::endl;
        roster.printByDegreeProgram(SOFTWARE); // Displays only students in Software degree program and lists out their data
        cout << std::endl;
    }
    

    roster.remove("A3"); // Removes student A3 and outputs updated studentdata
    cout << std::endl;


    roster.remove("A3");// Show that student A3 cannot be found
    cout << std::endl;
    
    cout << "Press enter to continue running";
    cin.get();// Replacement for system("pause) function

    return 0;
}
