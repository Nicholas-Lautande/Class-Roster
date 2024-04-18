//
//  main.cpp
//  Class Roster
//
//  Created by Nick Lautande on 4/17/24.
//

#include <iostream>
#include<string>
#include<array>
#include "roster.hpp"

int main() {
        
    cout <<"Course Title: C867 - SCRIPTING AND PROGRAMMING - APPLICATIONS"<< endl;
    cout << "Programming Language Used: C++ " << endl;
    cout << "Student ID: 011769202" << endl;
    cout << "Student Name: Nicholas Lautande" << endl;
    cout << "   " << endl;
    cout << "   " << endl;


  
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Nicholas,Lautande,nlautan@wgu.edu,22,22,33,55,SOFTWARE"
    };

    
    Roster * classRoster = new Roster(5);
    for (int i = 0; i < 5; i++) {
        classRoster->parse(studentData[i], i);
    };

 
    //functions
    classRoster->printAll();
    cout << endl;
  
    classRoster->printInvalidEmails();
    cout << endl << endl;
    
    for (int i = 0; i < 5; i++) {

            classRoster->printAverageDaysInCourse(classRoster->GetID(i));
        }
    cout << endl << endl;
    
    classRoster->printByDegreeProgram("SOFTWARE");
    cout << endl << endl;
    
    classRoster->remove("A3");
    cout << endl << endl;
    
    classRoster->printAll();
    
    classRoster->remove("A3");
    
    classRoster->~Roster();
    delete classRoster;
    cout << endl << endl;
    
    return 0;
}
