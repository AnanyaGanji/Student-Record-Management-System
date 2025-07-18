#include <iostream>
#include <string>
#include "LinkedList.h"
#include "UndoStack.h"
using namespace std;

UndoManager um;

void addStudent(LinkedList *ll) {
    string name, course;
    int rollno;
    float marks;
    cout << "Enter roll no, name, course and marks of the sudent:\n";
    cin >> rollno >> name >> course >> marks;
    ll->push(Student(rollno, name, course, marks));
    ll->display();
    um.recordAction("add", Student(rollno, name, course, marks));
}

void removeStudent(LinkedList *ll) {
    string name;
    cout << "Enter name of the student  to be removed:\n";
    cin >> name;
    Student s = ll->searchByName(name);
    Student removed = ll->pop(s);
    cout << "Removed the following student:\n";
    removed.display();
    um.recordAction("delete", removed);
}

void searchByName(LinkedList *ll) {
    string name;
    cout << "Enter the name of the student you want to search for:\n";
    cin >> name;
    Student toSearch = ll->searchByName(name);
}

void searchByRollno(LinkedList *ll) {
    int rollno;
    cout << "Enter the roll no of student you want to search for:\n";
    cin >> rollno;
    Student toSearch = ll->searchByRollNo(rollno);
}

void undo(LinkedList *ll) {
    um.undo(ll);
}

int main() {
    LinkedList *ll = new LinkedList();
    cout << "Hey! Welcome! What would you like to do?\n";
    int option;

    while (true) {
        cout << "1. Display all students\n2. Add a new student\n3. Remove a student\n4. Search a student by thier name\n5. Search a student by their roll no.\n6. Undo. \nPress 7 to exit\n";
        cin >> option;
        switch(option) {
            case 1:
                ll->display();
                break;
            case 2:
                addStudent(ll);
                break;
            case 3:
                removeStudent(ll);
                break;
            case 4:
                searchByName(ll);
                break;
            case 5:
                searchByRollno(ll);
                break;
            case 6:
                undo(ll);
                break;
            case 7:
                cout << "Thank you! GoodBye!!";
                return 0;

        }
    }
    return 0;
}
