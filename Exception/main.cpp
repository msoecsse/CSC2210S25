#include <iostream>

using namespace std;

// Function to perform division
float divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw runtime_error("Error: Division by zero is not allowed.");
    }
    // static_cast is used to convert the result to a float
    return static_cast<float>(numerator) / denominator;
}

int main() {
    int num, den;

    // cout << "Enter numerator: ";
    // cin >> num;
    // cout << "Enter denominator: ";
    // cin >> den;
    num = 10;
    den = 0;

    try {
        float result = divide(num, den);
        cout << "Result: " << result << endl;
    } catch (const runtime_error& e) {
        // what() is similar to the getMessage()
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "Program continues after exception handling." << endl;

    return 0;
}
