#include "student.h"

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
int daysInCourse3, string degreeprogram){
    //debug
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
    this->degreeProgram = getDegreeProgram(degreeprogram);
};

void Student::print(){
    cout <<  studentID << "\t";
    cout <<  "First Name: " + firstName << "\t";
    cout <<  "Last Name: " + lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}" << "\t";
    cout << "Degree Program: "  <<  getDegreeProgram(degreeProgram) << endl;
};

Student::~Student(){
    return;
}

int Student::getAvgDays(){return((daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3);}

DegreeProgram Student::getDegreeProgram(){
    return(this->degreeProgram);
}

string Student::getDegreeProgram(DegreeProgram prog){
    return( (const string[]){"Invalid Degree","SECURITY", "NETWORK", "SOFTWARE"}[degreeProgram] );
}

DegreeProgram Student::getDegreeProgram(string prog){
    string degrees[4] = {"Invalid Degree", "SECURITY", "NETWORK", "SOFTWARE"};
    for(int i = 0; i < 4; ++i ){
        if(prog == degrees[i]){return(DegreeProgram(i));}
    }
    return(NULLL);
}