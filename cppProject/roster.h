#include <string>
#include "student.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

class Roster{
    private:
	array<Student*, 5> classRosterArray;
    
    public:
        Roster(const string * studentData, unsigned int size);
        ~Roster();
	array<Student*,5> getStudents();
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
            int daysInCourse3, string degreeprogram);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
        Student* getStudentById(const string studentID);
};
