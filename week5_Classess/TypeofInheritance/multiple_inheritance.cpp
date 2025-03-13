#include <iostream>
using namespace std;

// First base class
class Flyer {
public:
    void fly() {
        cout << "Flying...\n";
    }
};

// Second base class
class Swimmer {
public:
    void swim() {
        cout << "Swimming...\n";
    }
};

// Derived class with multiple inheritance
class Duck : public Flyer, public Swimmer {
public:
    void quack() {
        cout << "Quacking...\n";
    }
};

int main() {
    Duck d;
    d.fly();   // Inherited from Flyer
    d.swim();  // Inherited from Swimmer
    d.quack(); // Duck's own function
    return 0;
}
