#pragma once
#ifndef DEGREE_H
#include <iostream>

using namespace std;

//Enumerated data type DegreeProgram
enum DegreeProgram {SECURITY, NETWORK, SOFTWARE, NONE}; // Requirement C for enum DegreeProgram; sets a default of NONE for degree

static const std::string DegreeProgramString[] = { "SECURITY", "NETWORK", "SOFTWARE", "NONE"}; 

#endif
