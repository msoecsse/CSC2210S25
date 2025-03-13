#include <iostream>
#include <stdexcept>

using namespace std;

// Custom exception class for division by zero
// Inherits from runtime_error
//runtime_error is a standard exception class defined in the <stdexcept> header
class DivisionByZeroException  {
public:
    DivisionByZeroException()
    : message("Error: Division by zero is not allowed.") {}
    // what() function is a standard function in the exception class
    // equivalent to getMessage() in Java
    const char* what() const {
        return message;
    }
private:
    const char* message;
};

// Function to perform division
float divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw DivisionByZeroException();
    }
    return static_cast<float>(numerator) / denominator;
}

// Custom terminate handler
void customTerminate() {
    cerr << "Unhandled exception occurred. Program terminating." << endl;
    exit(EXIT_FAILURE); // Ensures program exits cleanly
}

int main() {
    int num, den;

    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    try {
        float result = divide(num, den);
        cout << "Result: " << result << endl;
    } catch (const DivisionByZeroException& e) {
        cout << "Exception caught: " << e.what() << endl;
        // if not caught then terminate called which (by default) calls abort
    // terminate handler
    }
    set_terminate(customTerminate);
    // Case 1: Exception not caughts
    // since exception is not caught as it is out of try block
    // , terminate handler is called
    float result = divide(num, den);  // If denominator is 0, exception is thrown but not caught
    cout << "Result: " << result << endl;  // This line will not be executed
    cout << "Program continues after exception handling." << endl;

    return 0;
}
