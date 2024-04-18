//
//  roster.cpp
//  Class Roster
//
//  Created by Nick Lautande on 4/17/24.
//

#include "roster.hpp"
#include <iostream>
#include <string>
#include <array>

using namespace std;

Roster::Roster(int size)
{
    this->size = size;
    for(int i = 0; i < size; i++)
    {
        this->classRosterArray[i] = new Student();
    }
}
void Roster::parse(string student, int i)
{
    string ID;
    string firstName;
    string lastName;
    string email;
    int age;
    int days1;
    int days2;
    int days3;
        
        int start = student.find(",");
        ID = student.substr(0,start);
        classRosterArray[i]->SetID(ID);
        
        int startNext = start + 1;
        start = student.find(",",startNext);
        firstName = student.substr(startNext, start-startNext);
        classRosterArray[i]->SetFirstName(firstName);
        
        startNext = start + 1;
        start = student.find(",",startNext);
        lastName = student.substr(startNext, start-startNext);
        classRosterArray[i]->SetLastName(lastName);
        
        startNext = start + 1;
        start = student.find(",", startNext);
        email = student.substr(startNext, start-startNext);
        classRosterArray[i]->SetEmailAddress(email);
        
        startNext = start + 1;
        start = student.find(",", startNext);
        age = stoi(student.substr(startNext, start-startNext));
        classRosterArray[i]->SetAge(age);
        
        startNext = start + 1;
        start = student.find(",", startNext);
        days1 = stoi(student.substr(startNext, start-startNext));
        
        
        startNext = start + 1;
        start = student.find(",", startNext);
        days2 = stoi(student.substr(startNext, start-startNext));
        
        startNext = start + 1;
        start = student.find(",", startNext);
        days3 = stoi(student.substr(startNext, start-startNext));
        
        classRosterArray[i]->SetDaysInCourse(days1, days2, days3);
        
        startNext = start + 1;
        start = student.find(",", startNext);
        string degreeT = student.substr(startNext, start-startNext);
        
        if(degreeT == "SOFTWARE")
        {
            classRosterArray[i]->SetDegreeProgram(SOFTWARE);
        }
        else if(degreeT == "NETWORK")
        {
            classRosterArray[i]->SetDegreeProgram(NETWORK);
        }
        else if(degreeT == "SECURITY")
        {
            classRosterArray[i]->SetDegreeProgram(SECURITY);
        }
        else
        {
            cout << "Error: Degree not found." << endl;
        }
    
}
void Roster::add(string ID, string fName, string lName, string email, int age, int days1, int days2, int days3, DegreeProgram degree)
{
    int daysLeft[3] = {days1,days2,days3};
    classRosterArray[size] = new Student(ID, fName, lName, email, age, daysLeft, degree);
}
string Roster::GetID(int num)
{
    string student = classRosterArray[num]->GetStudentID();
    return student;
}
void Roster::remove(string studentID)
{
    for (int i = 0; i < size; ++i) {
            if (classRosterArray[i] == nullptr) {
                cout << "Error: The student ID you entered does not match our records";
                break;
            }
            else if (studentID == classRosterArray[i]->GetStudentID()) 
            {
                classRosterArray[i] = nullptr;
                cout << "Student removed" << endl;
            }
        }


}
void Roster::printAll()
{
    for(int i = 0; i < size; i = i)
    {
        if(classRosterArray[i] != nullptr)
        {
            cout << classRosterArray[i]->GetStudentID() << "   First Name: " << classRosterArray[i]->GetFirstName() << "   Last Name: " << classRosterArray[i]->GetLastName() << "   Email: " << classRosterArray[i]->GetEmailAddress() << "   Age: " << classRosterArray[i]->GetAge() << "   daysInCourse: {" << classRosterArray[i]->GetDaysInCourse()[0]  << ", " << classRosterArray[i]->GetDaysInCourse()[1] << ", " << classRosterArray[i]->GetDaysInCourse()[2] << "}   Degree Program: " << classRosterArray[i]->GetDegree() << endl << endl;
            i++;
        }
        else{
            i++;
        }
        
    }
}
void Roster::printAverageDaysInCourse(string studentID)
{
    for(int i = 0; i < size; i++)
    {
        if(studentID == classRosterArray[i]->GetStudentID())
        {
            int num1 = classRosterArray[i]->GetDaysInCourse()[0];
            int num2 = classRosterArray[i]->GetDaysInCourse()[1];
            int num3 = classRosterArray[i]->GetDaysInCourse()[2];
            int avg = (num1 + num2 + num3) / 3;
            cout << "This student has an average of " << avg << " days left in their courses." << endl;
        }
    }
}
void Roster::printInvalidEmails()
{
    for(int i = 0; i < size; i++)
    {
        string validOrNot = classRosterArray[i]->GetEmailAddress();
        if(validOrNot.find('.') == string::npos || validOrNot.find('@') == string::npos || validOrNot.find(' ') != string::npos)
        {
            cout << classRosterArray[i]->GetEmailAddress() << " is not a valid email address." << endl;
        }
    }
}
void Roster::printByDegreeProgram(string degree)
{
    cout << "Students in this degree program: " << endl;
    for(int i = 0; i < size; i++)
    {
        if(classRosterArray[i]->GetDegree() == degree)
        {
            cout << "-" << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << endl;
        }
    }
}
Roster::~Roster()
{
    for(int i = 0; i < size; i++)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
