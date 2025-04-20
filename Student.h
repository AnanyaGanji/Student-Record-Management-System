#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student {
    public:
    int rollNo;
    string name;
    string course;
    float marks;

    Student(int rollNo, string name, string course, float marks) : rollNo(rollNo), name(name), course(course), marks(marks)
    {}

    void display() {
        cout << "Student Detials:\nRoll no: " << rollNo << "\nName: " << name << "\nCourse: " << course << "\nMarks: " << marks << "\n"<< endl;
    }
    
};
