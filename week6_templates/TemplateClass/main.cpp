#include <iostream>
#include <string>

// ==================================================
// Template class
// ==================================================
template <typename T>
class Box {
public:
    // Constructor taking a const reference to T
    // Using 'explicit' to avoid implicit conversions
    explicit Box(const T& val) : value(val) {}
// we use the explicit keyword to avoid implicit conversions. This means that the compiler will not automatically convert a value to a Box object.
// Instead, we must explicitly create a Box object by calling the constructor.
// for  example, if we try to create a Box object with an integer value, the compiler will not automatically convert the integer to a Box object. Instead, we must explicitly create a Box object by calling the constructor.

    // Suppose we do NOT use explicit here:
    //Box(int val) : value(val) {}

    // Getter
    T getValue() const {
        return value;
    }

    // Setter
    void setValue(const T& val) {
        value = val;
    }

private:
    T value;
};

int main() {
    // 1) Create a Box<int>
   Box<int> intBox(10);
    std::cout << "intBox contains: " << intBox.getValue() << std::endl;
// when we create a Box object with an integer value, the compiler will
// automatically convert the integer to a Box object.
// This is because the constructor is not marked as explicit, so the compiler can perform an implicit conversion.
     //Box b = 100;
    // effectively becomes:
    // Box b(100);


    // 2) Create a Box<std::string>
    Box<std::string> strBox("Hello, templates!");
    std::cout << "strBox contains: " << strBox.getValue() << std::endl;


    // 3)  modifying the value in Box<int>
    intBox.setValue(42);
    std::cout << "intBox changed to: " << intBox.getValue() << std::endl;

// common pitfall: if you do not use the explicit keyword, the compiler may perform implicit conversions that you did not intend. This can lead to unexpected behavior in your code.
// for example, if we try to create a Box object with an integer value,
// the compiler will automatically convert the integer to a Box object.
// This is because the constructor is not marked as explicit,
// so the compiler can perform an implicit conversion.


    return 0;
}
