#include <iostream>
#include <string>

// =======================
// 1. FUNCTION OVERLOADING
// =======================

// Overloaded function #1: Takes an int
void display(int value) {
    std::cout << "Integer value: " << value << std::endl;
}

// Overloaded function #2: Takes a double
void display(double value) {
    std::cout << "Double value: " << value << std::endl;
}

// Overloaded function #3: Takes a string
void display(const std::string &value) {
    std::cout << "String value: " << value << std::endl;
}

// =======================
// 2. OPERATOR OVERLOADING
// =======================

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Operator+ overload to add two Complex numbers
    Complex operator+(const Complex &other) const {
        // Return a new Complex instance with summed real and imaginary parts
        return Complex(this.real + other.real, imag + other.imag);
    }

    // Operator - overload to subrtract two complex number
    Complex operator-(const Complex &other) const {
        // Return a new Complex instance with subracted real and imaginary parts
        return Complex(real - other.real, imag - other.imag);
    }

    // For convenience, we overload the << operator to print a Complex object
    friend std::ostream &operator<<(std::ostream &out, const Complex &c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

};

int main() {
    // FUNCTION OVERLOADING
    display(42);               // Calls display(int)
    display(3.14159);          // Calls display(double)
    display(std::string("Hello, World!"));  // Calls display(const std::string&)

    // OPERATOR OVERLOADING
    Complex c1(1.5, 2.5);
    Complex c2(3.0, 4.0);

    Complex c3 = c1 + c2;  // Uses operator+ to add two Complex numbers
    Complex c4 = c1 - c2;  // Uses operator- to subract two Complex numbers

    std::cout << "c1 = " << c1 << std::endl; // Prints the values of c1 and c2
    std::cout << "c2 = " << c2 << std::endl; // Prints the values of c1 and c2
    std::cout << "c3 = c1 + c2 = " << c3 << std::endl; // Prints the result of the addition
    std::cout << "c4 = c1 - c2 = " << c4 << std::endl; // Prints the result of the substraction

    return 0;
}
