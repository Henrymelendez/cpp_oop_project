#include <iostream>
#include <sstream>
#include "roster.h"


int main() {
    // Display the course title, programming language, student ID, and name
    std::cout << "Course Title: Software Development - C++\n";
    std::cout << "Programming Language Used: C++\n";
    std::cout << "Student ID: 011454191\n";
    std::cout << "Name: Henry Melendez\n\n";

    // Student data table
    const std::string studentData[] = {
            "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
            "A5,Henry,Melendez,hmele18@wgu.edu,34,22,45,50,SOFTWARE"
    };

    Roster classRoster(5);

    for(int i = 0; i < 5; i++) {
        std::istringstream ss(studentData[i]);
        std::string token;

        std::string studentID;
        std::string firstName;
        std::string lastName;
        std::string email;
        int age;
        int daysInCourse[3];
        DegreeProgram degreeProgram;

        // Parse the string and extract each piece of data
        std::getline(ss, studentID, ',');
        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, email, ',');
        ss >> age;
        for (int j = 0; j < 3; j++) {
            ss.ignore();
            ss >> daysInCourse[j];
        }
        ss.ignore();
        std::string degreeStr;
        std::getline(ss, degreeStr, ',');

        if (degreeStr == "SECURITY") degreeProgram = SECURITY;
        else if (degreeStr == "NETWORK") degreeProgram = NETWORK;
        else if (degreeStr == "SOFTWARE") degreeProgram = SOFTWARE;

        // Add the student to the roster
        classRoster.add(studentID, firstName, lastName, email, age, daysInCourse[0], daysInCourse[1], daysInCourse[2], degreeProgram);
    }

    // Printing all student data
    std::cout << "Displaying all students:\n";
    classRoster.printAll();
    std::cout << "\n";

    // Printing invalid emails
    std::cout << "Displaying invalid emails:\n";
    classRoster.printInvalidEmails();
    std::cout << "\n";

    // Printing average days in course
    std::cout << "Displaying average days in course:\n";
    for (int i = 0; i <= classRoster.getLastIndex(); i++) {
        classRoster.printAverageDaysInCourse(classRoster.getStudent(i)->getStudentID());
    }
    std::cout << "\n";

    // Printing students by degree program
    std::cout << "Displaying students in the SOFTWARE program:\n";
    classRoster.printByDegreeProgram(SOFTWARE);
    std::cout << "\n";

    // Removing a student
    std::cout << "Removing student A3:\n";
    classRoster.remove("A3");
    classRoster.printAll();
    std::cout << "\n";

    // Attempting to remove the same student again
    std::cout << "Attempting to remove student A3 again:\n";
    classRoster.remove("A3");

    return 0;

}
