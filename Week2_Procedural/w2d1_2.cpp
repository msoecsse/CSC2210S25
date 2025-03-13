#include <iostream>
#include <string>
using namespace std;

//////////////demo.cpp///////////////////////
/// introduction to using cin and cout

// function to calculate the cube of a number
double cube(double num) { //function definition
    return num * num * num; //return the cube of the number
}
int main() {
    // my first program in C++
    // print to console
        std::cout << "Hello World! \n";
        cout << "Hello CSC2210!";



    //print to console
    cout << "Hello, World!" << endl;
    //read from console
    string name;
    cout << "What is your name? \n"; //prompt user for input
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

//    // Variables and Data Types
    int age = 20;
    double weight = 65.5;
    bool isMale = true;
    string name1 = "Alice";
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << endl;
    cout << "Name: " << name1 << endl;
    char grade = 'A';
    cout << "Grade: " << grade << endl;
    
// Modify your program so it reads a number from the user and prints its cube. A sample run will be the following:

    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The cube of " << num << " is " << num * num * num << endl;
     double num1;
    cout << "Enter a double number: ";
    cin >> num1;
    cout << "The cube of a double is " << num1 << " is " << num1 * num1 * num1 << endl;

    //using a function
    double num3;
    cout << "Enter a double number: ";
    cin >> num3;
    cout << "The cube of " << num3 << " is " << cube(num3) << endl;




    return 0;

}












