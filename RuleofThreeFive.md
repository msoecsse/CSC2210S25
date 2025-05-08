# Rule of Three and Five in C/C++

## Shallow Copy vs Deep Copy
In C++, when copying objects, there are two types of copying: shallow copy and deep copy.
- **Shallow Copy**: A shallow copy creates a new object that shares the same memory as the original object. This means that if the original object is modified, the copied object will also reflect those changes. Shallow copies are typically created using the default copy constructor and copy assignment operator provided by the compiler.
- **Deep Copy**: A deep copy creates a new object that has its own copy of the data. This means that if the original object is modified, the copied object will not be affected. Deep copies are typically created by defining a custom copy constructor and copy assignment operator that allocate new memory for the copied data.
- **Example of Shallow Copy**:
```cpp
#include <iostream>
class Shallow {
private:
    int* data;
public:

    Shallow(int value) {
        data = new int(value);
    }

    // Default copy constructor (shallow copy)
    Shallow(const Shallow& other) : data(other.data) {}

    void print() const {
        std::cout << *data << std::endl;
    }
};
int main() {
    Shallow obj1(42);
    Shallow obj2 = obj1; // Shallow copy

    obj1.print(); // Output: 42
    obj2.print(); // Output: 42

    *obj1.data = 100; // Modifying obj1 affects obj2

    obj1.print(); // Output: 100
    obj2.print(); // Output: 100 (undefined behavior, both point to the same memory)

    return 0;
}
```
- **Example of Deep Copy**:
```cpp
#include <iostream>
class Deep {
private:
    int* data;
public:

    Deep(int value) {
        data = new int(value);
    }

    // Custom copy constructor (deep copy)
    Deep(const Deep& other) {
        data = new int(*other.data);
    }

    ~Deep() {
        delete data;
    }

    void print() const {
        std::cout << *data << std::endl;
    }
};
int main() {
    Deep obj1(42);
    Deep obj2 = obj1; // Deep copy

    obj1.print(); // Output: 42
    obj2.print(); // Output: 42

    *obj1.data = 100; // Modifying obj1 does not affect obj2

    obj1.print(); // Output: 100
    obj2.print(); // Output: 42 (independent copies)

    return 0;
}
```
## Introduction
In C++, the Rule of Three and Rule of Five are important concepts related to resource management, particularly when dealing with dynamic memory allocation. These rules help developers understand when to implement custom copy constructors, copy assignment operators, move constructors, and move assignment operators to ensure proper resource management and avoid memory leaks or undefined behavior.
## Rule of Zero
The Rule of Zero is a guideline in C++ programming that states that classes should not manage resources directly. Instead, they should rely on existing classes (like `std::string`, `std::vector`, etc.) to handle resource management. This approach simplifies code and reduces the risk of memory leaks and undefined behavior.
### When to Use the Rule of Zero
- **Use Standard Library Containers**: Instead of managing raw pointers or dynamic memory, use standard library containers like `std::vector`, `std::string`, or `std::unique_ptr` that automatically manage their resources.
- **Avoid Manual Memory Management**: Avoid using `new` and `delete` for dynamic memory allocation. Instead, use smart pointers like `std::unique_ptr` or `std::shared_ptr` that automatically manage memory.
- **Encapsulate Resource Management**: If your class needs to manage resources, encapsulate that management in a separate class that follows the Rule of Zero. This way, your class can focus on its core functionality without worrying about resource management.
- **Use RAII (Resource Acquisition Is Initialization)**: Use the RAII pattern to manage resources. This means that resources are acquired in the constructor and released in the destructor, ensuring that resources are properly managed without manual intervention.
- **Avoid Raw Pointers**: Avoid using raw pointers in your classes. Instead, use smart pointers or standard library containers that automatically manage memory.
- **Use Move Semantics**: In modern C++, use move semantics to transfer ownership of resources instead of copying them. This reduces the need for custom copy constructors and assignment operators.
- **Use `std::unique_ptr` or `std::shared_ptr`**: Use smart pointers to manage dynamic memory. These pointers automatically deallocate memory when they go out of scope, reducing the risk of memory leaks.
- **Use `std::string` for Strings**: Use `std::string` instead of raw character arrays for string management. `std::string` automatically manages memory and provides a rich set of functionalities for string manipulation.
- **Use `std::vector` for Arrays**: Use `std::vector` instead of raw arrays for dynamic arrays. `std::vector` automatically manages memory and provides a rich set of functionalities for array manipulation.
- **Use `std::map` or `std::unordered_map` for Key-Value Pairs**: Use `std::map` or `std::unordered_map` instead of raw pointers for key-value pairs. These containers automatically manage memory and provide efficient access to elements.

### Example of Rule of Zero
```cpp
#include <iostream>
#include <vector>
#include <string>
class RuleOfZero {
private:
    std::vector<int> data; // Automatically managed by std::vector
    std::string name; // Automatically managed by std::string
public:
    RuleOfZero(const std::string& n) : name(n) {
        data.push_back(1);
        data.push_back(2);
        data.push_back(3);
    }
    void print() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Data: ";
        for (const auto& d : data) {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    } 
};
int main() {
    RuleOfZero obj("Example");
    obj.print(); // Output: Name: Example, Data: 1 2 3

    return 0;
}
```
### Explanation
- **Rule of Zero**: The class `RuleOfZero` does not manage any resources directly. It uses `std::vector` and `std::string`, which automatically manage their resources.
- **Automatic Resource Management**: The `std::vector` and `std::string` members automatically handle memory allocation and deallocation, reducing the risk of memory leaks and undefined behavior.
- **No Custom Destructor**: The class does not require a custom destructor, copy constructor, or copy assignment operator, as the standard library containers handle resource management.
- **Output**: The program prints the name and data of the object, demonstrating that the class works correctly without manual resource management.

### Explanation
- **Rule of Zero**: The class `RuleOfZero` does not manage any resources directly. It uses `std::vector` and `std::string`, which automatically manage their resources.
- **Automatic Resource Management**: The `std::vector` and `std::string` members automatically handle memory allocation and deallocation, reducing the risk of memory leaks and undefined behavior.
- **No Custom Destructor**: The class does not require a custom destructor, copy constructor, or copy assignment operator, as the standard library containers handle resource management.
- **Output**: The program prints the name and data of the object, demonstrating that the class works correctly without manual resource management

## Rule of Three
The Rule of Three is a guideline in C++ programming that states if a class requires a user-defined destructor, copy constructor, or copy assignment operator, it likely requires all three. This rule is important for managing resources such as dynamic memory, file handles, or network connections.
### When to Use the Rule of Three
- **Dynamic Memory Management**: If your class allocates memory dynamically (e.g., using `new`), you need to define a destructor to free that memory.
- **Copying Objects**: If your class manages resources that cannot be copied by default (e.g., pointers), you need to define a copy constructor and copy assignment operator to ensure proper copying of those resources.
- **Resource Management**: If your class manages resources that require special handling (e.g., file handles, network connections), you need to define a destructor to release those resources when the object goes out of scope.
- **Non-Trivial Copying**: If your class has non-trivial copying semantics (e.g., deep copying), you need to define a copy constructor and copy assignment operator to ensure proper copying of those resources.
- **Inheritance**: If your class is intended to be used as a base class, you need to define a virtual destructor to ensure proper cleanup of derived classes.
- **Polymorphism**: If your class is intended to be used with polymorphism, you need to define a virtual destructor to ensure proper cleanup of derived classes.
- **RAII**: If your class uses the RAII (Resource Acquisition Is Initialization) pattern, you need to define a destructor to ensure proper cleanup of resources when the object goes out of scope.


### Example of Rule of Three
```cpp
#include <iostream>
#include <cstring>
class String {  
private:
    char* str;
public:
    // Constructor
    String(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Copy Constructor
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Copy Assignment Operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str; // Free existing resource
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    void print() const {
        std::cout << str << std::endl;
    }
};
int main() {
    String s1("Hello");
    String s2 = s1; // Calls copy constructor
    String s3("World");
    s3 = s1; // Calls copy assignment operator

    s1.print(); // Output: Hello
    s2.print(); // Output: Hello
    s3.print(); // Output: Hello

    return 0;
}
```
### Explanation
- **Constructor**: Allocates memory for the string and copies the input string.
- **Destructor**: Frees the allocated memory when the object goes out of scope.
- **Copy Constructor**: Creates a new object as a copy of an existing object, allocating new memory for the string.
- **Copy Assignment Operator**: Assigns one object to another, ensuring that existing memory is freed before allocating new memory for the string.
- **Output**: The program prints the string "Hello" three times, demonstrating that the copy constructor and copy assignment operator work correctly.
## Rule of Five
The Rule of Five is an extension of the Rule of Three, introduced in C++11, which states that if a class requires a user-defined destructor, copy constructor, or copy assignment operator, it likely requires all five special member functions: destructor, copy constructor, copy assignment operator, move constructor, and move assignment operator. This rule is important for managing resources efficiently in modern C++.
### When to Use the Rule of Five
- **Dynamic Memory Management**: If your class allocates memory dynamically (e.g., using `new`), you need to define a destructor to free that memory.
- **Copying Objects**: If your class manages resources that cannot be copied by default (e.g., pointers), you need to define a copy constructor and copy assignment operator to ensure proper copying of those resources.
- **Moving Objects**: If your class manages resources that can be moved (e.g., pointers), you need to define a move constructor and move assignment operator to ensure proper moving of those resources.
- **Resource Management**: If your class manages resources that require special handling (e.g., file handles, network connections), you need to define a destructor to release those resources when the object goes out of scope.
- **Non-Trivial Copying**: If your class has non-trivial copying semantics (e.g., deep copying), you need to define a copy constructor and copy assignment operator to ensure proper copying of those resources.
- **Non-Trivial Moving**: If your class has non-trivial moving semantics (e.g., shallow copying), you need to define a move constructor and move assignment operator to ensure proper moving of those resources.
- **Inheritance**: If your class is intended to be used as a base class, you need to define a virtual destructor to ensure proper cleanup of derived classes.
- **Polymorphism**: If your class is intended to be used with polymorphism, you need to define a virtual destructor to ensure proper cleanup of derived classes.        
- **RAII**: If your class uses the RAII (Resource Acquisition Is Initialization) pattern, you need to define a destructor to ensure proper cleanup of resources when the object goes out of scope.

## Example of Rule of Five
```cpp
#include <iostream>
#include <cstring>
class String {
private:
    char* str;
public: 

    // Constructor
    String(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Copy Constructor
    String(const String& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Copy Assignment Operator
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str; // Free existing resource
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        }
        return *this;
    }
    // Move Constructor
    String(String&& other) noexcept : str(other.str) {
        other.str = nullptr; // Leave the moved-from object in a valid state
    }
    // Move Assignment Operator
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] str; // Free existing resource
            str = other.str; // Transfer ownership
            other.str = nullptr; // Leave the moved-from object in a valid state
        }
        return *this;
    }
    void print() const {
        std::cout << str << std::endl;
    }
};  
int main() {
    String s1("Hello");
    String s2 = std::move(s1); // Calls move constructor
    String s3("World");
    s3 = std::move(s2); // Calls move assignment operator

    s1.print(); // Output: (undefined behavior, s1 is in a moved-from state)
    s2.print(); // Output: (undefined behavior, s2 is in a moved-from state)
    s3.print(); // Output: Hello

    return 0;
}
```
### Explanation
- **Constructor**: Allocates memory for the string and copies the input string.
- **Destructor**: Frees the allocated memory when the object goes out of scope.
- **Copy Constructor**: Creates a new object as a copy of an existing object, allocating new memory for the string.
- **Copy Assignment Operator**: Assigns one object to another, ensuring that existing memory is freed before allocating new memory for the string.
- **Move Constructor**: Transfers ownership of the string from one object to another, leaving the moved-from object in a valid state.
- **Move Assignment Operator**: Transfers ownership of the string from one object to another, ensuring that existing memory is freed before transferring ownership.
- **Output**: The program prints the string "Hello" once, demonstrating that the move constructor and move assignment operator work correctly. The moved-from objects are left in a valid state, but their contents are undefined.
- **Note**: After moving, the moved-from object should not be used unless it is assigned a new value or reset to a valid state. Accessing the moved-from object may lead to undefined behavior.
## Conclusion
The Rule of Three and Rule of Five are important guidelines in C++ programming for managing resources effectively. By following these rules, you can ensure that your classes handle resource management correctly, preventing memory leaks and undefined behavior. Understanding these rules is essential for writing robust and maintainable C++ code.
## References
- [C++ Programming Language](https://www.stroustrup.com/)
- [Effective C++](https://www.oreilly.com/library/view/effective-c-55/9780132771671/)
- [Modern C++ Design](https://www.oreilly.com/library/view/modern-c-design/9780201704416/)
- [C++ Primer](https://www.oreilly.com/library/view/c-primer-5th/9780133055545/)
- 