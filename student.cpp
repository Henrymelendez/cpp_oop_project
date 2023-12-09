//
// Created by Henry Melendez on 12/4/23.
//

#include "student.h"
#include "degree.h"
#include <iostream>
#include <iomanip> // for std::setw and std::left

// Constructor implementation
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
                 int *daysToComplete, DegreeProgram degreeProgram)
                 : studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age),
                 degreeProgram(degreeProgram) {
    for(int i = 0; i < 3; i++){
        this->daysToComplete[i] = daysToComplete[i];
    }

};
// Destructor
Student::~Student(){};

// Accessor implementations
std::string Student::getStudentID() const {return studentID;}
std::string Student::getFirstName() const {return firstName;}
std::string Student::getLastName() const {return lastName;}
std::string Student::getEmailAddress() const {return emailAddress;}
int Student::getAge() const {return age;}
const int* Student::getDaysToCompleteEachCourse() const {return daysToComplete;}
DegreeProgram Student::getDegreeProgram() const {return degreeProgram;}

// Mutator implementations
void Student::setStudentId(std::string studentId) { this->studentID = studentId;}
void Student::setFirstName(std::string firstname) { this->firstName = firstname;}
void Student::setLastName(std::string lastName) { this->lastName = lastName;}
void Student::setEmailAddress(std::string emailAddress) { this->emailAddress = emailAddress;}
void Student::setAge(int age) { this->age = age;}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram=degreeProgram;}
void Student::setDaysToCompleteEachCourse(int daysToComplete[]) {
    for(int i = 0; i < 3; i++){
        this->daysToComplete[i] = daysToComplete[i];
    }
}
// Helper method for print formatting
std::string DegreeProgramToString(DegreeProgram dp) {
    switch (dp) {
        case SECURITY:
            return "SECURITY";
        case NETWORK:
            return "NETWORK";
        case SOFTWARE:
            return "SOFTWARE";
        default:
            return "UNKNOWN";
    }
}
// Print function to output student data in a formatted manner
void Student::print() const {
    std::cout << std::left << std::setw(10) << "Student ID: " << studentID << "\t";
    std::cout << std::left << std::setw(10) <<  "First Name: " << firstName << "\t";
    std::cout << std::left << std::setw(10) << "Last Name: " << lastName << "\t";
    std::cout << std::left << std::setw(5) << "Email: " << emailAddress << "\t";
    std::cout << std::right << std::setw(15) << "Age: " << age << "\t";
    std::cout << std::right << std::setw(35) << "Days in Course: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}\t";
    std::cout << std::right << std::setw(35) << "Degree Program: " << DegreeProgramToString(degreeProgram) << std::endl;
}