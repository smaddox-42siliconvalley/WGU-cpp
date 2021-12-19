#include <string>
#include "student.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

class Roster{
    private:
        vector<Student*> students;
        vector<Student*> classRosterArray;
    
    public:
        Roster(const string * studentData, unsigned int size);
        ~Roster();
        vector<Student*> getStudents();
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
            int daysInCourse3, string degreeprogram);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(string degreeProgram);
        Student* getStudentById(string studentID);
};