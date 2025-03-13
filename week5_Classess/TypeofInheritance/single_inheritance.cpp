#include <iostream>
using namespace std;

// Base class
class Animal {
protected:
    void eat() {
        cout << "Eating...\n";
    }
};

// Derived class (single inheritance from Animal)
class Dog : private Animal {
public:
    void bark() {
        cout << "Barking...\n";
    }
};

int main() {
    Dog d;
    d.eat();   // Inherited from Animal
    d.bark();  // Defined in Dog
    return 0;
}
//
// Created by bhattacharya on 2/27/2025.
//
