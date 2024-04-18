//
//  student.cpp
//  Class Roster
//
//  Created by Nick Lautande on 4/17/24.
//

#include "student.hpp"
#include <string>
#include "student.hpp"

using namespace std;

Student::Student()
{
    this->ID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    this->daysLeft[0] = 0;
    this->daysLeft[1] = 0;
    this->daysLeft[2] = 0;
    this->degreeType = SECURITY;
}
Student::Student(string ID, string firstName, string lastName, string email, int age, int daysLeft[], DegreeProgram degreeType)
{
    this->ID = ID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->daysLeft[0] = daysLeft[0];
    this->daysLeft[1] = daysLeft[1];
    this->daysLeft[2] = daysLeft[2];
    this->degreeType = degreeType;
}

string Student::GetStudentID()
{
    return ID;
}
string Student::GetFirstName()
{
    return firstName;
}
string Student::GetLastName()
{
    return lastName;
}
string Student::GetEmailAddress()
{
    return email;
}
int Student::GetAge()
{
    return age;
}
int* Student::GetDaysInCourse()
{
    return daysLeft;
}
string Student::GetDegree()
{
    return degreeType;
}
void Student::SetID(string studentID)
{
    this->ID = studentID;
}
void Student::SetFirstName(string fName)
{
    this->firstName = fName;
}
void Student::SetLastName(string lName)
{
    this->lastName = lName;
}
void Student::SetEmailAddress(string emailAddress)
{
    this->email = emailAddress;
}
void Student::SetAge(int age)
{
    this->age = age;
}
void Student::SetDaysInCourse(int days1, int days2, int days3)
{
    this->daysLeft[0] = days1;
    this->daysLeft[1] = days2;
    this->daysLeft[2] = days3;
}
void Student::SetDegreeProgram(DegreeProgram degree)
{
    string dType;
    if(degree == NETWORK)
    {
        dType = "NETWORK";
    }
    else if(degree == SOFTWARE)
    {
        dType = "SOFTWARE";
    }
    else if(degree == SECURITY)
    {
        dType = "SECURITY";
    }
    this->degreeType = dType;
}
