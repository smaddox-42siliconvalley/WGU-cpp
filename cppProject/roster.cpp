#include "roster.h"

Roster::Roster(const string * studentData, unsigned int size){
    int i = -1;
    string temp;
    vector<string> result;
    while(++i < size){

        //tokenize string
        stringstream strstream(studentData[i]);
        while(getline(strstream, temp, ',')){
            result.push_back(temp);
        }

        //add student
        this->add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stoi(result[6]), stoi(result[7]), result[8]);

        //prep for the next iteration
        result.clear();
    }
}

vector<Student*> Roster::getStudents(){
    return(this->students);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
            int daysInCourse3, string degreeprogram){
                this->students.push_back(new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2,
                    daysInCourse3, degreeprogram));
            }

void Roster::remove(string studentid){
    vector<int> iter;
    for( auto iter = this->students.begin(); iter != this->students.end(); iter++){
        if((*iter)->getStudentID() == studentid){
            delete(*iter);
            this->students.erase(iter);
            return;
        }
    }
    cout << "Student not found" << endl;
}

void Roster::printAll(){
    for_each(this->students.begin(), this->students.end(), [](Student * student){student->print();});
}
        
Student* Roster::getStudentById(string studentId){
    Student * result_student = nullptr;
    for_each(this->students.begin(), this->students.end(), [studentId, &result_student](Student * student){
        if(student->getStudentID() == studentId) {result_student = student;}});
    return(result_student);
}
        
void Roster::printAverageDaysInCourse(string studentID){
    Student * student = this->getStudentById(studentID);
    if(student){
        cout << student->getStudentID() << " : " << "Average Days enrolled: " << student->getAvgDays() << endl;
    }
    else{
        cout << "No student found: " << studentID << endl;
    }
}

void Roster::printInvalidEmails(){
    for_each(this->students.begin(), this->students.end(), [](Student * student){
        if(!((student->getEmail().find("@") != std::string::npos) && 
            (student->getEmail().find(".") != std::string::npos) && 
            (student->getEmail().find(" ") == std::string::npos))){
               cout << "Email belonging to:" << student->getStudentID() << "\n" << student->getEmail() << " is invalid" << endl;
            }
    });
}