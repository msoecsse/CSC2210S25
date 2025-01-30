#include <iostream>
using namespace std; // using directive namespace

int main() {
    std::cout << "Hello, World!" << std::endl;

// if statement
    int x = 10;
    if (x > 5) {
        cout << "x is greater than 5" << endl;
    }

// if else statement
    if (x > 5) {
        cout << "x is greater than 5" << endl;
    } else {
        cout << "x is less than 5" << endl;
    }
    // ternary operator
    cout << (x > 5 ? "x is greater than 5" : "x is less than 5") << endl;

    // while loop
    int i = 0;
    while (i < 10) {
        cout << "i is = " << i << endl;
        i++;
    }
    int product = 3;
    while (product <= 100) {
        product = 3 * product;
        cout << product << endl;   // 3, 9, 27, 81, 243
        }

// Problem1: class average
    int total = 0;
    // int total{0}; // uniform initialization syntax
    // uniform initialization syntax is used to initialize variables
    int grade;
    int average;
    int counter = 0;
    while (counter < 10) {
        cout << "Enter grade: ";
        cin >> grade;
        total = total + grade;
        counter++;
    }
    average = total / 10;
    cout << "Class average is: " << average << endl;

    // real-estate problem
    int pass = 0;
    unsigned pass2 = 0; // unsigned integer is used to store only positive values

    int fail = 0;
    int studentCounter = 1;
    while (studentCounter <= 10) {
        cout << "Enter result (1 = pass, 2 = fail): ";
        int result;
        cin >> result;
        if (result == 1) {
            pass++;
        } else {
            fail++;
        }
        studentCounter++;
        if (pass > 8) {
            cout << "Bonus to instructor!" << endl;
        }
    }




// for loop
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
    }

    // for (int i = 0; i < 10; ++i) { // pre-increment
    //     cout << i << endl;
    // }
// while loop
  int f = 0;
    while (f < 10) {
        cout << "i is = " << f << endl;
        f++;
    }

// do while loop
// do while loop is used to execute the block of code at least once
    int j = 0;
    do {
        cout << "j is = " << j << endl;
        j++;
    } while (j < 10);

// Problem2: class average
    int total2 = 0;
    int grade2;
    int average2;
    int counter2 = 0;
    do {
        cout << "Enter grade: ";
        cin >> grade2;
        total2 = total2 + grade2;
        counter2++;
    } while (counter2 < 10);
    average2 = total2 / 10;
    cout << "Class average is: " << average2 << endl;

    // switch statement
    int choice;
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "You entered 1" << endl;
            break;
        case 2:
            cout << "You entered 2" << endl;
            break;
        case 3:
            cout << "You entered 3" << endl;
            break; // break statement is used to exit the switch statement
        default:
            cout << "You entered something else" << endl;
    }

// continue statement is used to skip the current iteration of the loop
    // demo
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            continue;
        }
        cout << i << endl;
    }

    // short circuit evaluation
    // short circuit evaluation is used to evaluate the expression from left to right
    // if the first condition is false, then the second condition is not evaluated
    // and vice versa

    int a = 5;
    int b = 0;
    if (b != 0 && a / b > 2) {
        // if b is not equal to 0 and a divided by b is greater than 2
        cout << "a is greater than 2b" << endl;
    } else {
        cout << "a is not greater than 2b" << endl;
    }

    // logical operators
    // && - logical AND
    // || - logical OR
    // ! - logical NOT
    int c = 5;
    int d = 0;
    if (c != 0 && c / d > 2) {
        cout << "a is greater than 2b" << endl;
    } else {
        cout << "a is not greater than 2b" << endl;
    }



    return 0;
}
