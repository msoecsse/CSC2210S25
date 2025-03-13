//
// Created by bhattacharya on 2/27/2025.
//
#include <iostream>
using namespace std;

// Top-level base class
class Person {
public:
    void sayHello() {
        cout << "Hello!\n";
    }
};

// Derived from Person
class Student : public Person {
public:
    void study() {
        cout << "Studying...\n";
    }
};

// Further derived from Student
class GraduateStudent : public Student {
public:
    void doResearch() {
        cout << "Conducting research...\n";
    }
};

int main() {
    GraduateStudent gs;
    gs.sayHello();   // Inherited from Person
    gs.study();      // Inherited from Student
    gs.doResearch(); // Defined in GraduateStudent
    return 0;
}
