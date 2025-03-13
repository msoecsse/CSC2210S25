//
// Created by bhattacharya on 2/27/2025.
//
#include <iostream>
using namespace std;

// Base classes
class ElectronicDevice {
public:
    void powerOn() {
        cout << "Power on.\n";
    }
};

class Rechargeable {
public:
    void charge() {
        cout << "Charging...\n";
    }
};

// Derived from both base classes (multiple inheritance)
class Phone : public ElectronicDevice, public Rechargeable {
public:
    void call() {
        cout << "Making a call...\n";
    }
};

// Now we do a hierarchical-style derivation from the same base classes
class Laptop : public ElectronicDevice, public Rechargeable {
public:
    void code() {
        cout << "Coding on laptop...\n";
    }
};

// Another class derived from Phone (multilevel style)
class SmartPhone : public Phone {
public:
    void useApps() {
        cout << "Using apps...\n";
    }
};

int main() {
    Phone p;
    Laptop l;
    SmartPhone s;

    cout << "-- Phone --\n";
    p.powerOn();
    p.charge();
    p.call();

    cout << "\n-- Laptop --\n";
    l.powerOn();
    l.charge();
    l.code();

    cout << "\n-- SmartPhone --\n";
    s.powerOn();  // from ElectronicDevice
    s.charge();   // from Rechargeable
    s.call();     // from Phone
    s.useApps();  // defined in SmartPhone

    return 0;
}
