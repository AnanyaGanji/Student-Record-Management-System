#pragma once
#include "Student.h"

class Node {
    public:
    Student student;
    Node *next;
    Node *prev;

    Node(Student student) : student(student), next(nullptr), prev(nullptr)
    {}
};

class LinkedList {
    public:
    Node *head;
    Node *tail;

    LinkedList() : head(nullptr), tail(nullptr)
    {}

    void push(Student s) {
        Node *nn = new Node(s);
        if (head == nullptr) {
            head = nn;
            tail = nn;
            return;
        }

        tail->next = nn;
        nn->prev = tail;
        tail = tail->next;
        return;
    }

    Student pop(Student s) {
        if (head->student.name == s.name) {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return s;
        }

        if (tail->student.name == s.name) {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            return s;
        }


        Node *temp = head;
        while (temp->student.name != s.name && temp != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        return s;
    }

    void display() {
        Node *temp = head;
        while (temp != nullptr) {
            temp->student.display();
            temp = temp->next;
        }
        return;
    }

    int length() {
        Node *temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    Student searchByName(string name) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->student.name == name) {
                temp->student.display();
                return temp->student;
            }
            temp = temp->next;
        }
        cout << "No such student found\n";
        return Student(0,"","",0.0);
    }

    Student searchByRollNo(int rollno) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->student.rollNo == rollno) {
                temp->student.display();
                return temp->student;
            }
            temp = temp->next;
        }
        cout << "No such student found\n";
        return Student(0,"","",0.0);
    }
};
