#include <iostream>
#include "roster.h"
using namespace std;


int main(){
	//Input Data
	const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "004718925,Samuel,Maddox,samuelmaddox1@gmail.com,25,30,30,30,SOFTWARE"};

	Roster classRoster = Roster(studentData, 5);

	cout << "Course: Scripting and Programming Applicaitons" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #004718925" << endl;
	cout << "Name: Samuel Maddox" << endl;

	cout << "----------------------------------------------------------" << endl;
	classRoster.printAll();
	cout << "----------------------------------------------------------" << endl;
	classRoster.printInvalidEmails();
	cout << "----------------------------------------------------------" << endl;

	//Getter for classRosterArray
	array<Student*, 5> studs = classRoster.getStudents();
	//loop through the classRosterArray 
	for_each(studs.begin(), studs.end(), [&classRoster](Student * student){
		classRoster.printAverageDaysInCourse(student->getStudentID());
	    });


	cout << "----------------------------------------------------------" << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	cout << "----------------------------------------------------------" << endl;
	classRoster.printAll();
	cout << "----------------------------------------------------------" << endl;
	classRoster.remove("A3");
	return(0);
}
