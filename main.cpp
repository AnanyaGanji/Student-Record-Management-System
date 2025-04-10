#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList *ll = new LinkedList();
    Student s1(101, "Alice", "Research", 89.00);
    Student s2(102, "Bob", "Chemistry", 90.00);
    Student s3(103, "Charlie", "Architecture", 95.00);
    Student s4(104, "Gwen", "Economics", 69.00);
    ll->push(s1);
    ll->push(s2);
    ll->push(s3);
    ll->push(s4);
    ll->display();
    cout <<"Length of ll is: " << ll->length() << endl;
    ll->searchByName("Gwen");
    ll->searchByRollNo(104);
    cout << "popping\n";
    ll->pop(s3);
    ll->display();
    cout <<"Popping:\n";
    ll->pop(s2).display();
    cout <<"After pop\n";
    ll->display();
}
