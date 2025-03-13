#include <iostream>

// ************ COMPILE-TIME POLYMORPHISM ************
int add(int a, int b) {
    return a + b;
}

// Overloaded function with different parameter type
double add(double a, double b) {
    return a + b;
}

// Overloaded function with a different number of parameters
int add(int a, int b, int c) {
    return a + b + c;
}
//Base Class
class Shape {
public:
    // Virtual function for polymorphic behavior
    virtual void draw() const {
        std::cout << "Drawing a generic shape.\n";
    }

    // Virtual destructor ensures proper cleanup in derived classes
    virtual ~Shape() {}
};
// Derived Class

class Circle : public Shape {
public:
    // Override the base class function
    void draw() const override {
        std::cout << "Drawing a circle.\n";
    }
};

class Rectangle : public Shape {
public:
    // Override the base class function
    void draw() const override {
        std::cout << "Drawing a rectangle.\n";
    }
};

void showShape(const Shape& shapeRef) {
  //Shape*++;
    // Which draw() gets called depends on the ACTUAL type of shapeRef
    // This is decided at RUN-TIME
    shapeRef.draw();
}

int main() {
    // ************ COMPILE-TIME POLYMORPHISM ************
    std::cout << "add(3, 4)          = " << add(3, 4) << "\n";
    std::cout << "add(2.5, 3.5)      = " << add(2.5, 3.5) << "\n";
    std::cout << "add(1, 2, 3)       = " << add(1, 2, 3) << "\n\n";

    // ************ RUN-TIME POLYMORPHISM ************
    Shape shape;  //
    Circle circle;
    Rectangle rectangle;

    // Show shapes using references
    showShape(shape);      // Calls Shape::draw
    showShape(circle);     // Calls Circle::draw
    showShape(rectangle);  // Calls Rectangle::draw

    return 0;
}
