#include <iostream>
#include <memory>
#include <stdexcept>

class A {
public:
    A() {
        std::cout << "Constructing A\n";
        // Simulate an error by throwing an exception
        // the constructor throws an exception without creating an object
        throw std::runtime_error("A failed!");
    }
    // Destructor (~A) is never called for the failed object.
    ~A() { std::cout << "Destroying A\n"; }
};

class B {
public:
    B() {
        std::cout << "Constructing B\n";
    }
    ~B() { std::cout << "Destroying B\n"; }
};

class C: public A, public B {
    A a; // This will throw an exception
    B b;
public:
    C() try : a(), b() { // A throws, C’s constructor will fail
        // When a (a member of C) is constructed, it again throws an exception.

        std::cout << "Constructing C\n";
    } catch (const std::exception& e) {
        std::cerr << "Exception in C: " << e.what() << std::endl;
        // The try block catches the exception, prints an error, and rethrows it.
        throw; // Propagates the exception; cannot suppress it
    }
    // Since the constructor failed, the destructor is never called for C.
    ~C() { std::cout << "Destroying C\n"; } // Never called if constructor fails
};
// Class D (Safe Resource Management)
class D: public A, public B{
    std::unique_ptr<B> optionalMember;
public:
    D(bool fail) {
        try {
            // If fail == true, it throws an exception immediately.
            //The exception is caught, an error is printed, and the exception is rethrown

            if (fail) {
                throw std::runtime_error("D failed!");
            }
            // If fail == false, it creates a B object and assigns it to optionalMember.
            // Uses std::unique_ptr:optionalMember is a std::unique_ptr<B>, which is initialized only
//            if construction succeeds.
                        optionalMember = std::make_unique<B>(); // Safe optional member
            std::cout << "Constructing D\n";
        } catch (const std::exception& e) {
            std::cerr << "Exception in D: " << e.what() << std::endl;
            throw; // Propagates exception
        }
    }
    ~D() { std::cout << "Destroying D\n"; }
};

int main() {
    // Since A throws an exception, C fails to construct.
//    The exception is caught, and "Caught exception in main: A failed!" is printed.

    try {
        C c; // This will fail due to A's exception
    } catch (const std::exception& e) {

        std::cerr << "Caught exception in main: " << e.what() << std::endl;
    }
    // Calls D(true), which throws an exception immediately.
    //The exception is caught, and "Caught exception in main (D): D failed!" is printed.
    try {
        D d(true); // This will fail due to exception in D
    } catch (const std::exception& e) {
        std::cerr << "Caught exception in main (D): " << e.what() << std::endl;
    }
    // Calls D(false), meaning D successfully constructs.
    // "Constructing B" and "Constructing D" are printed.
    // "Destroying D" is printed when the destructor is called.
    try {
        D d(false); // Successful construction
    } catch (const std::exception& e) {
        std::cerr << "Caught exception in main (D success case): " << e.what() << std::endl;
    }

    return 0;
}
