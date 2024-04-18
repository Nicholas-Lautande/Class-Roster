//
//  roster.hpp
//  Class Roster
//
//  Created by Nick Lautande on 4/17/24.
//

#ifndef roster_hpp
#define roster_hpp

#include <string>
#include <array>
#include <iostream>
#include "student.hpp"

using namespace std;


class Roster
{
public:
    Student* classRosterArray[5];
    Roster(int size);
    void add(string ID, string fName, string lName, string email, int age, int days1, int days2, int days3, DegreeProgram degree);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(string degree);
    void parse(string student, int i);
    string GetID(int num);
    ~Roster();
    
private:
    int size;
};

#endif /* roster_hpp */
