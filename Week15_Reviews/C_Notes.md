# C typedef and Struct  Notes

### C typedef and Struct Notes
- `typedef` is a keyword in C that allows you to create an alias for a data type. It is often used to simplify complex type definitions or to create more meaningful names for existing types.
- `struct` is a user-defined data type in C that allows you to group different data types together. It is used to create complex data structures that can hold multiple values of different types.
- `typedef` can be used with `struct` to create a new type name for a structure, making it easier to work with.
- `typedef` can be used with pointers to create more readable code, especially when dealing with function pointers or complex data structures.
- `struct` can be used to create linked lists, trees, and other data structures that require dynamic memory allocation.

### Example Code
```c

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Define a structure to represent a point in 2D space
    struct Point {
        int x;
        int y;
    };

    // Create an alias for the Point structure using typedef
    typedef struct Point Point;

    // Create a variable of type Point
    Point p1;
    p1.x = 10; // accessing members using dot operator
    p1.y = 20;

    // Print the coordinates of the point
    printf("Point coordinates: (%d, %d)\n", p1.x, p1.y);

    return 0;
}
```

#### Example Code with Pointers
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to demonstrate typedef with pointers
typedef struct {
    int x;
    int y;
} Point;
typedef Point* PointPtr; // here PointPtr is a pointer to Point
typedef Point** PointPtrPtr; // here PointPtrPtr is a pointer to a pointer to Point
// a double pointer to a Point is a pointer to a pointer to a Point
typedef Point*** PointPtrPtrPtr; // here PointPtrPtrPtr is a pointer to a pointer to a pointer to Point

// Function to demonstrate typedef with function pointers
typedef void (*FuncPtr)(int); // Function pointer type that takes an int argument and returns void
typedef void (*FuncPtrPtr)(int, int); // Function pointer type that takes two int arguments and returns void

void printPoint(Point p) { // here Point is passed by value 
    printf("Point coordinates: (%d, %d)\n", p.x, p.y); // accessing members using dot operator
}
void printPointPtr(PointPtr p) { // here PointPtr is passed by reference
    printf("Point coordinates: (%d, %d)\n", p->x, p->y); // accessing members using arrow operator
}
void printPointPtrPtr(PointPtrPtr p) { // here PointPtrPtr is passed by reference
    printf("Point coordinates: (%d, %d)\n", (*p)->x, (*p)->y); // accessing members using arrow operator
}
void printPointPtrPtrPtr(PointPtrPtrPtr p) {
    printf("Point coordinates: (%d, %d)\n", (**p)->x, (**p)->y); // accessing members using arrow operator
}
void add(int a, int b) {
    printf("Sum: %d\n", a + b);
}
void subtract(int a, int b) {
    printf("Difference: %d\n", a - b);
}
void multiply(int a, int b) {
    printf("Product: %d\n", a * b);
}
void divide(int a, int b) {
    if (b != 0) {
        printf("Quotient: %d\n", a / b);
    } else {
        printf("Division by zero error\n");
    }
}
void callFunction(FuncPtr func, int arg) {
    func(arg);
}
void callFunctionPtr(FuncPtrPtr func, int arg1, int arg2) {
    func(arg1, arg2);
}
int main() {
    // Create a Point variable
    Point p1;
    p1.x = 10;
    p1.y = 20;

    // Create a pointer to the Point variable
    PointPtr pPtr = &p1; // here pPtr is a pointer to Point

    // Create a pointer to the pointer to the Point variable
    PointPtrPtr pPtrPtr = &pPtr; // here pPtrPtr is a pointer to a pointer to Point &# here pPtr is a pointer to Point

    // Create a pointer to the pointer to the pointer to the Point variable
    PointPtrPtrPtr pPtrPtrPtr = &pPtrPtr;

    // Print the coordinates of the point using different levels of indirection
    printPoint(p1);
    printPointPtr(pPtr);
    printPointPtrPtr(pPtrPtr);
    printPointPtrPtrPtr(pPtrPtrPtr);

    // Call functions using function pointers
    FuncPtr func = add;
    callFunction(func, 5);

    FuncPtr func2 = subtract;
    callFunction(func2, 10);

    FuncPtr func3 = multiply;
    callFunction(func3, 15);

    FuncPtr func4 = divide;
    callFunction(func4, 20);

    return 0;
}
```

## Example Code with Structs and Typedef
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define a structure to represent a point in 2D space
typedef struct {
    int x;
    int y;
} Point;
typedef struct {
    Point p1;
    Point p2;
} Line;
typedef struct {
    Line l1;
    Line l2;
} Rectangle;
typedef struct {
    Rectangle r1;
    Rectangle r2;
} Square;
typedef struct {
    Square s1;
    Square s2;
} Cube;



// Function to demonstrate typedef with structs
void printPoint(Point p) {
    printf("Point coordinates: (%d, %d)\n", p.x, p.y);
}
void printLine(Line l) {
    printf("Line coordinates: (%d, %d) to (%d, %d)\n", l.p1.x, l.p1.y, l.p2.x, l.p2.y);
}
void printRectangle(Rectangle r) {
    printf("Rectangle coordinates: (%d, %d) to (%d, %d)\n", r.l1.p1.x, r.l1.p1.y, r.l2.p2.x, r.l2.p2.y);
}
void printSquare(Square s) {
    printf("Square coordinates: (%d, %d) to (%d, %d)\n", s.s1.r1.l1.p1.x, s.s1.r1.l1.p1.y, s.s2.r2.l2.p2.x, s.s2.r2.l2.p2.y);
}
void printCube(Cube c) {
    printf("Cube coordinates: (%d, %d) to (%d, %d)\n", c.c1.s1.r1.l1.p1.x, c.c1.s1.r1.l1.p1.y
              , c.c2.s2.r2.l2.p2.x, c.c2.s2.r2.l2.p2.y);
}


int main() {
    // Create a Point variable
    Point p1;
    p1.x = 10;
    p1.y = 20;

    // Create a Line variable
    Line l1;
    l1.p1 = p1;
    l1.p2.x = 30;
    l1.p2.y = 40;

    // Create a Rectangle variable
    Rectangle r1;
    r1.l1 = l1;
    r1.l2.p1.x = 50;
    r1.l2.p1.y = 60;

    // Create a Square variable
    Square s1;
    s1.s1.r1 = r1;
    s1.s2.r2.p2.x = 70;
    s1.s2.r2.p2.y = 80;
    // Create a Cube variable
    Cube c1;
    c1.c1.s1 = s1;
    c1.c2.s2.r2.p2.x = 90;
    c1.c2.s2.r2.p2.y = 100;

    // Print the coordinates of the point, line, rectangle, square, and cube
    printPoint(p1);
    printLine(l1);
    printRectangle(r1);
    printSquare(s1);
    printCube(c1);
    return 0;
}
```

## Templates in C++
- Templates feature in C++ that allows you to write generic and reusable code. They enable you to create functions and classes that can work with any data type without the need for explicit type definitions.
- Templates are particularly useful for creating data structures and algorithms that can operate on different types of data, such as arrays, linked lists, and trees.
- Templates can be used to create function templates and class templates.
- Function templates allow you to create a single function definition that can work with different data types. The compiler generates the appropriate function based on the type of arguments passed to it.
- Class templates allow you to create a class definition that can work with different data types. The compiler generates the appropriate class based on the type of data used to instantiate it.
- Templates can be specialized to provide specific implementations for certain data types. This allows you to customize the behavior of templates for specific cases while still maintaining the generic functionality.
- Templates can be used with standard library containers, such as vectors, lists, and maps, to create generic data structures that can hold different types of data.
- Templates can be used with algorithms, such as sorting and searching, to create generic functions that can operate on different types of data.


### Example Code to demonstrate function templates and class templates
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
// Function template to find the maximum of two values
template <typename T typename U>
T findMax(T a, U b) {
    return (a > b) ? a : b;
}
// Class template to represent a pair of values
template <typename T, typename U>
class Pair {
public:
    T first;
    U second;

    Pair(T f, U s) : first(f), second(s) {}

    void display() {
        cout << "First: " << first << ", Second: " << second << endl;
    }
};

int main() {
    // Using function template
    int a = 10;
    double b = 20.5;
    cout << "Max: " << findMax(a, b) << endl;

    // Using class template
    Pair<int, string> p1(1, "Hello");
    p1.display();

    Pair<double, char> p2(3.14, 'A');
    p2.display();

    return 0;
}
```









