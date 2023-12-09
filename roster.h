//
// Created by Henry Melendez on 12/4/23.
//

#ifndef ROSTER_H
#define ROSTER_H
#include <string>
#include "student.h"


class Roster {
private:
    Student** classRosterArray;
    int lastIndex;
    int capacity;

public:
    Roster(int capacity);
    ~Roster();
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll() const;
    void printAverageDaysInCourse(std::string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    int getLastIndex() const;
    Student* getStudent(std::string studentID) const;
    Student* getStudent(int index) const;
};


#endif //ROSTER_H
