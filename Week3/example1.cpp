// Cube a variable using call-by-reference
//  with a pointer argument


#include <iostream>

using std::cout;
using std::endl;

void cubeByReference( int * );   // prototype

int main() {
     // Using the & and * operators
     int a;        // a is an integer
     int *aPtr;    // aPtr is a pointer to an integer

     a = 7;
     aPtr = &a;    // aPtr set to address of a

     cout << "The address of a is " << &a
          << "\nThe value of aPtr is " << aPtr;

     cout << "\n\nThe value of a is " << a
          << "\nThe value of *aPtr is " << *aPtr;

     cout << "\n\nShowing that * and & are inverses of "
          << "each other.\n&*aPtr = " << &*aPtr
          << "\n*&aPtr = " << *&aPtr << endl;

//
//
    int number = 5;

    cout << "The original value of number is " << number;
    cubeByReference( &number );
    cout << "\nThe new value of number is " << number << endl;
    return 0;
}

void cubeByReference( int *nPtr )
{
    // *nPtr is the data stored at &number memory location
    *nPtr = *nPtr * *nPtr * *nPtr;  // cube number in main
}



