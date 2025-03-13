#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    void startEngine() {
        cout << "Engine started.\n";
    }
};

// Derived classes from the same base class
class Car : public Vehicle {
public:
    void drive() {
        cout << "Car driving.\n";
    }
};

class Truck : public Vehicle {
public:
    void haul() {
        cout << "Truck hauling.\n";
    }
};

class Bus : public Vehicle {
public:
    void transportPassengers() {
        cout << "Bus transporting passengers.\n";
    }
};

int main() {
    Car c;
    Truck t;
    Bus b;

    c.startEngine();
    c.drive();

    t.startEngine();
    t.haul();

    b.startEngine();
    b.transportPassengers();

    return 0;
}
