#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

/*
        DONT FORGET TO CHANGE THE DEGREEPROGRAM DATATYPE TO THE ENUMERATED ONE
*/

class Student{
    private: 
        string studentID;
        string firstName;
        string lastName;
        string email;
        DegreeProgram degreeProgram;
        int age;
        int daysInCourse[3];
    public:
        // Constructor
        Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
            int daysInCourse2, int daysInCourse3, string degreeprogram);
        // destructor
        ~Student();

       //setters
       int setStudentID(string ID) { studentID = ID; return(0); }
       int setFirstName(string name) { firstName = name; return(0); }
       int setLastName(string name) { lastName = name; return(0); } 
       int setEmail(string Email) {email = Email; return(0); }
       int setAge(int Age) {age = Age; return(0); }
       int setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
           daysInCourse[0] = daysInCourse1;
           daysInCourse[1] = daysInCourse2;
           daysInCourse[2] = daysInCourse3;
           return(0);
       }

       //getters
       string getStudentID() { return(studentID); }
       string getFirstName() { return(firstName); }
       string getLastName() { return(lastName); }
       string getEmail() { return(email); }
       int getAge() { return(age); }
       int * getDaysInCourses() { return(daysInCourse); }
       int getAvgDays();
       string getDegreeProgram(DegreeProgram prog);
       DegreeProgram getDegreeProgram();
       DegreeProgram getDegreeProgram(string prog);


       //other funcs
       void print();

};

