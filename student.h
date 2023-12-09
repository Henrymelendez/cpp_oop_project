//
// Created by Henry Melendez on 12/4/23.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"

class Student {
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;
public:
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram);

    ~Student();
    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    const int* getDaysToCompleteEachCourse() const;
    DegreeProgram getDegreeProgram() const;

    void setStudentId(std::string studentId);
    void setFirstName(std::string firstname);
    void setLastName(std::string lastName);
    void setEmailAddress(std::string emailAddress);
    void setAge(int age);
    void setDaysToCompleteEachCourse(int daysToComplete[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    void print() const;

};


#endif //STUDENT_H
