#include "roster.h"

Roster::Roster(const string * studentData, unsigned int size){
	this->classRosterArray.fill(NULL);
	int i = -1;
	string temp;
	vector<string> result;

	while(++i < size){
	//tokenize string
		stringstream strstream(studentData[i]);
		while(getline(strstream, temp, ',')){
			    result.push_back(temp);
			}

		this->add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stoi(result[6]), stoi(result[7]), result[8]);

        //prep for the next iteration
		result.clear();
    }
}

Roster::~Roster(){
	for_each(classRosterArray.begin(), classRosterArray.end(), [](Student* student){
		delete(student);
	}); 
}

array<Student*, 5> Roster::getStudents(){
	return(this->classRosterArray);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
            int daysInCourse3, string degreeprogram){
		for( auto i = this->classRosterArray.begin(); i != this->classRosterArray.end(); i++ ){
			if( *i == NULL ){
				*i = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2,
                    			daysInCourse3, degreeprogram);
				return;
			}
		}
		cout << "Error: Class Roster Array is full; Student not added" << endl;
}

void Roster::remove(string studentid){
	for( auto i = this->classRosterArray.begin(); i != this->classRosterArray.end(); i++ ){
		if( (*i != NULL) && (*i)->getStudentID() == studentid ){
			delete(*i);
			*i = NULL;
			return;
		}
	}
	cout << "Student not found" << endl;
}

void Roster::printAll(){
	for_each(this->classRosterArray.begin(), this->classRosterArray.end(), [](Student * student){
		if ( student != NULL ){
			student->print();
		}
	});
}
        
Student* Roster::getStudentById(const string studentId){
    Student * result_student = NULL;
    for_each(classRosterArray.begin(), classRosterArray.end(), [studentId, &result_student](Student * student){
        if((student) && (student->getStudentID() == studentId)) {result_student = student;}});
    return(result_student);
}
        
void Roster::printAverageDaysInCourse(string studentID){
	string ID = studentID;
    Student * student = getStudentById(ID);
    if(student){
        cout << student->getStudentID() << " : " << "Average Days enrolled: " << student->getAvgDays() << endl;
    }
    else{
        cout << "No student found: " << ID << endl;
    }
}

void Roster::printInvalidEmails(){
    for_each(this->classRosterArray.begin(), this->classRosterArray.end(), [](Student * student){
        if(student && !((student->getEmail().find("@") != std::string::npos) && 
            (student->getEmail().find(".") != std::string::npos) && 
            (student->getEmail().find(" ") == std::string::npos))){
               cout << "Email belonging to:" << student->getStudentID() << "\n" << student->getEmail() << " is invalid" << endl;
            }
    });
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    for_each(this->classRosterArray.begin(), this->classRosterArray.end(), [degreeProgram](Student * student){
        if(student->getDegreeProgram() == degreeProgram){
            student->print();
        }
    });

}
