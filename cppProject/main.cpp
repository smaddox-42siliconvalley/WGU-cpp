#include <iostream>
#include "roster.h"
using namespace std;


int main(){
    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Samuel,Maddox,samuelmaddox1@gmail.com,25,30,30,30,SOFTWARE"};

    //create a new roster with studentData and size thereof; Roster(data, size)
    Roster  roster = Roster(studentData, (*(&studentData + 1) - studentData));
    vector<Student*> studs = roster.getStudents();
    roster.printAll();
    /*
    for_each(studs.begin(), studs.end(), [roster](Student * student){
        roster->printAverageDaysInCourse(student->getStudentID());
    });
    */

    //classRoster.printByDegreeProgram(SOFTWARE);
   // roster->remove("A3");
   // roster->printAll();
    //roster->remove("A3");


    return(0);
}