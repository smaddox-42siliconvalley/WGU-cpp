#include "student.h"

//constructor

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
int daysInCourse3, string degreeprogram){
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

//setters

int Student::setStudentID(string ID){
	studentID = ID;
	return(0);
}

int Student::setFirstName(string name){
	firstName = name;
	return(0);
}

int Student::setLastName(string name){
	lastName = name;
	return(0);
}

int Student::setEmail(string Email){
	email = Email;
	return(0);
}

int Student::setAge(int Age){
	age = Age;
	return(0);	
}

int Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3){
	daysInCourse[0] = daysInCourse1; 
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	return(0);
}

//getters

string Student::getStudentID(){
	return(studentID);
}

string Student::getFirstName(){
	return(firstName);
}

string Student::getLastName(){
	return(lastName);
}

string Student::getEmail(){
	return(email);
}

int Student::getAge(){
	return(age);
}

int* Student::getDaysInCourses(){
	return(daysInCourse);
}

//other funcs

void Student::print(){
    cout <<  studentID << "\t" << flush;
    cout <<  "First Name: " + firstName << "\t" << flush;
    cout <<  "Last Name: " + lastName << "\t" << flush;
    cout << "Age: " << age << "\t" << flush;
    cout << "daysInCourse: {" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}" << "\t" << flush;
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
    return(INVALID);
}
