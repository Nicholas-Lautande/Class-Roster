//
//  student.hpp
//  Class Roster
//
//  Created by Nick Lautande on 4/17/24.
//

#ifndef student_hpp
#define student_hpp
#include <iostream>
#include <string>
#include "degree.hpp"
using namespace std;

class Student{
public:
    Student();
    Student(string ID, string firstName, string lastName, string email, int age, int daysLeft[], DegreeProgram degreeType);
    string GetStudentID();
    string GetFirstName();
    string GetLastName();
    string GetEmailAddress();
    int GetAge();
    int* GetDaysInCourse();
    void SetID(string studentID);
    void SetFirstName(string fName);
    void SetLastName(string lName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetDaysInCourse(int days1, int days2, int days3);
    void SetDegreeProgram(DegreeProgram degree);
    string GetDegree();
    
    
    
private:
    string ID;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysLeft[3];
    string degreeType;
    
    
};




#endif /* student_hpp */
