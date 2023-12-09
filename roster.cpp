//
// Created by Henry Melendez on 12/4/23.
//

#include "roster.h"
#include <iostream>
//  headers here

// Constructor for the Roster class
// Initializes the array of student pointers with a given capacity

Roster::Roster(int capacity) {
    this->capacity = capacity;
    lastIndex = -1; // Initially, there are no students in the roster
    classRosterArray = new Student*[capacity]; // Allocate memory for the student pointers
}
// Destructor for the Roster class
// Releases the dynamically allocated memory to prevent memory leaks
Roster::~Roster(){
    for(int i = 0; i <= lastIndex; i++){
        delete classRosterArray[i]; // Delete each student object
        classRosterArray[i] = nullptr; // Set the pointer to nullptr
    }
    delete [] classRosterArray; // Delete the array of pointers
}

int Roster::getLastIndex() const {
    return lastIndex;
}


// Adds a student to the roster
// Parameters: studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram
// Creates a new student object and adds it to the classRosterArray
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress , age,
                                                daysInCourse, degreeProgram);
}

// Removes a student from the roster by their student ID
// If the student is not found, it prints an error message
void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            lastIndex--;
            found = true;
            break;
        }
    }
    if(!found){
            std::cout << "Error: Student with ID " << studentID << " not found.\n";
    }

    }
// Prints all student data
// Loops through the classRosterArray and calls the print function for each student
void Roster::printAll() const {
    for(int i =0; i <= lastIndex; i++){
        classRosterArray[i]->print();
    }
}
// Verifies student email addresses and displays all invalid email addresses
// A valid email should include an '@' and '.', and should not include a space
void Roster::printInvalidEmails() const {
    for(int i =0; i <= lastIndex; i++){
        std::string email = classRosterArray[i]->getEmailAddress();
        if(email.find('@') == std::string::npos || email.find('.') == std::string::npos || email.find(' ') != std::string::npos){
            std::cout << "Invalid email: " << email << std::endl;
        }
    }
}
// Prints average days in course for a given student
// Identified by the studentID parameter
void Roster::printAverageDaysInCourse(std::string studentID) const {
    for (int i =0 ; i <= lastIndex; i++){
        if(classRosterArray[i]->getStudentID() == studentID){
            int* days = const_cast<int*>(classRosterArray[i]->getDaysToCompleteEachCourse());
            std::cout << "Average days in course for student ID " << studentID << " is " << (days[0] + days[1] + days[2]) / 3.0 << std::endl;
            return;
        }
    }
    std::cout << "Student not found.\n";
}
// Prints out student information for a specific degree program
// The degree program is specified by an enumerated type
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for(int i = 0; i <= lastIndex; i++){
        if(classRosterArray[i]->getDegreeProgram() == degreeProgram){
            classRosterArray[i]->print();
        }
    }
}

Student* Roster::getStudent(std::string studentID) const {
    for(int i = 0; i <= lastIndex; i++){
        if(classRosterArray[i]->getStudentID() == studentID){
            return  classRosterArray[i];
        }
    }
    return nullptr;
}
Student* Roster::getStudent(int index) const {
    if (index >= 0 && index <= lastIndex) {
        return classRosterArray[index];
    } else {
        return nullptr; // Return nullptr if index is out of bounds
    }
}