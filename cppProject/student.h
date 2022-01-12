#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

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
       int setStudentID(string ID);
       int setFirstName(string name);
       int setLastName(string name); 
       int setEmail(string Email);
       int setAge(int Age);
       int setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
       

       //getters
       string getStudentID();
       string getFirstName();
       string getLastName();
       string getEmail();
       int getAge();
       int * getDaysInCourses();
       int getAvgDays();
       string getDegreeProgram(DegreeProgram prog);
       DegreeProgram getDegreeProgram();
       DegreeProgram getDegreeProgram(string prog);


       //other funcs
       void print();

};

