#pragma once
#include <string>
#include <stack>
#include "Student.h"
#include "LinkedList.h"
using namespace std;

struct Action {
    string type;
    Student student;
};

class UndoManager {
    public:
    stack<Action> undoStack;

    void recordAction(string type, Student s) {
        undoStack.push({type, s});
    }

    void undo(LinkedList *ll) {
        if (undoStack.empty()) {
            cout << "Nothing left to undo";
            return;
        }

        Action last = undoStack.top();
        undoStack.pop();
        if (last.type == "add") {
            ll->pop(last.student);
            return;
        }
        if (last.type == "delete") {
            ll->push(last.student);
            return;
        }
    }
};
