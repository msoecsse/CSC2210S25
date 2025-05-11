
# C++ Inheritance Notes

### Inheritance in C++
[]: # Inheritance is a fundamental concept in object-oriented programming that allows a class (derived class) to inherit
[]: # properties and behaviors (methods) from another class (base class). This promotes code reusability and establishes a hierarchical relationship between classes.
[]: # 
[]: # ### Types of Inheritance
[]: # 1. **Single Inheritance**: A derived class inherits from a single base class.
[]: # 2. **Multiple Inheritance**: A derived class inherits from multiple base classes.
[]: # 3. **Multilevel Inheritance**: A derived class inherits from a base class, which in turn inherits from another base class.
[]: # 4. **Hierarchical Inheritance**: Multiple derived classes inherit from a single base class.
[]: # 5. **Hybrid Inheritance**: A combination of two or more types of inheritance.
[]: # 
[]: # ### Syntax
[]: # ```cpp
[]: # class Base {
[]: # public:
[]: #     void display() {
[]: #         cout << "Base class display function" << endl;
[]: #     }
[]: # };
[]: # 
[]: # class Derived : public Base { // Single Inheritance
[]: # public:
[]: #     void show() {
[]: #         cout << "Derived class show function" << endl;
[]: #     }
[]: # };
[]: # 
[]: # int main() {
[]: #     Derived obj;
[]: #     obj.display(); // Accessing base class method
[]: #     obj.show();    // Accessing derived class method
[]: #     return 0;
[]: # }
[]: # ```
[]: # 
[]: # ### Access Specifiers
[]: # - **public**: Members are accessible from outside the class.
[]: # - **protected**: Members are accessible within the class and derived classes.
[]: # - **private**: Members are accessible only within the class.

# Virtual Functions
- Virtual functions enable dynamic (runtime) polymorphism. They allow derived classes to override base class methods.
- When a base class pointer points to a derived class object, the derived class's overridden method is called.
- We use the `virtual` keyword in the base class method declaration.

```cpp
class Base {
public:
    virtual void display() { // Virtual function
        cout << "Base class display function" << endl;
    }
};
class Derived : public Base {
public:
    void display() override { // Overriding base class method
        cout << "Derived class display function" << endl;
    }
};
int main() {
    Base* ptr; // Base class pointer
    Derived obj; // Derived class object
    ptr = &obj; // Pointing to derived class object

    ptr->display(); // Calls derived class method due to virtual function

    return 0;
}
```
# Pure Virtual Functions
- A pure virtual function is a virtual function that has no implementation in the base class and must be overridden in derived classes.
- It is declared by assigning `0` to the function declaration in the base class.
- A class with at least one pure virtual function is an abstract class and cannot be instantiated.

```cpp
class AbstractBase {
public:
    virtual void display() = 0; // Pure virtual function
};
class Derived : public AbstractBase {
public:
    void display() override { // Overriding pure virtual function
        cout << "Derived class display function" << endl;
    }
};
int main() {
    // AbstractBase obj; // Error: Cannot instantiate abstract class
    Derived obj; // Derived class object
    obj.display(); // Calls derived class method
    return 0;
}
```

# Abstract Classes
- An abstract class is a class that contains at least one pure virtual function.
- It cannot be instantiated directly.
- Derived classes must implement all pure virtual functions to be instantiated.

```cpp
class AbstractBase {
public:
    virtual void display() = 0; // Pure virtual function
};
class Derived : public AbstractBase {
public:
    void display() override { // Overriding pure virtual function
        cout << "Derived class display function" << endl;
    }
};
int main() {
    // AbstractBase obj; // Error: Cannot instantiate abstract class
    Derived obj; // Derived class object
    obj.display(); // Calls derived class method
    return 0;
}
```
# Multiple Inheritance
- Multiple inheritance allows a derived class to inherit from multiple base classes.
- It can lead to ambiguity if two base classes have methods with the same name.
- To resolve ambiguity, we can use the scope resolution operator `::` to specify which base class method to call.

```cpp  
class Base1 {
public:
    void display() {
        cout << "Base1 class display function" << endl;
    }
};
class Base2 {
public:
    void display() {
        cout << "Base2 class display function" << endl;
    }
};
class Derived : public Base1, public Base2 {
public:
    void display() {
        Base1::display(); // Calling Base1 display function
        Base2::display(); // Calling Base2 display function
    }
};
int main() {
    Derived obj;
    obj.display(); // Calls derived class display function
    return 0;
}
```
# Virtual Base Classes
- Virtual base classes are used to prevent multiple instances of a base class when using multiple inheritance.
- They ensure that only one instance of the base class is shared among derived classes.
- To declare a virtual base class, we use the `virtual` keyword in the inheritance list.

```cpp
class Base {
public:
    void display() {
        cout << "Base class display function" << endl;
    }
};
class Derived1 : virtual public Base { // Virtual base class
public:
    void show() {
        cout << "Derived1 class show function" << endl;
    }
};
class Derived2 : virtual public Base { // Virtual base class
public:
    void show() {
        cout << "Derived2 class show function" << endl;
    }
};
class Derived3 : public Derived1, public Derived2 {
public:
    void display() {
        Base::display(); // Calling base class display function
        Derived1::show(); // Calling Derived1 show function
        Derived2::show(); // Calling Derived2 show function
    }
};
int main() {
    Derived3 obj;
    obj.display(); // Calls base class and derived class methods
    return 0;   
}
```
# Friend Functions
- A friend function is a function that is not a member of a class but has access to its private and protected members.
- It is declared using the `friend` keyword inside the class.
- Friend functions can be useful for operator overloading and accessing private data of a class.

```cpp
class Box {
private:
    int length;
    int width;
public:
    Box(int l, int w) : length(l), width(w) {}
    friend void displayArea(Box b); // Friend function declaration
};
void displayArea(Box b) { // Friend function definition
    cout << "Area of the box: " << b.length * b.width << endl;
}
int main() {
    Box box(5, 10);
    displayArea(box); // Calling friend function
    return 0;
}
```

# Public, Protected, and Private Inheritance
- **Public Inheritance**: Members of the base class are accessible as public members in the derived class.
- **Protected Inheritance**: Members of the base class are accessible as protected members in the derived class.
- **Private Inheritance**: Members of the base class are accessible as private members in the derived class.
- The access specifier used in inheritance determines the accessibility of base class members in the derived class.

## Rules of Inheritance using access specifiers:
- **Public Inheritance**: Public members of the base class remain public in the derived class, protected members remain protected, and private members are not accessible.
- **Protected Inheritance**: Public and protected members of the base class become protected in the derived class, while private members remain inaccessible.
- **Private Inheritance**: Public and protected members of the base class become private in the derived class, while private members remain inaccessible.
```cpp
class Base {
public:
    int pubVar;
protected:
    int protVar;
private:
    int privVar;
};
class DerivedPublic : public Base { // Public Inheritance
public:
    void display() {
        cout << "Public Variable: " << pubVar << endl; // Accessible
        cout << "Protected Variable: " << protVar << endl; // Accessible
        // cout << "Private Variable: " << privVar << endl; // Not accessible
    }
};
class DerivedProtected : protected Base { // Protected Inheritance
public:
    void display() {
        cout << "Public Variable: " << pubVar << endl; // Accessible
        cout << "Protected Variable: " << protVar << endl; // Accessible
        // cout << "Private Variable: " << privVar << endl; // Not accessible
    }
};
class DerivedPrivate : private Base { // Private Inheritance
public:
    void display() {
        cout << "Public Variable: " << pubVar << endl; // Accessible
        cout << "Protected Variable: " << protVar << endl; // Accessible
        // cout << "Private Variable: " << privVar << endl; // Not accessible
    }
};
int main() {
    DerivedPublic obj1;
    obj1.pubVar = 10; // Accessible
    obj1.display();

    DerivedProtected obj2;
    // obj2.pubVar = 20; // Not accessible
    obj2.display();

    DerivedPrivate obj3;
    // obj3.pubVar = 30; // Not accessible
    obj3.display();

    return 0;
}
```
# Polymorphism
- Polymorphism is the ability of a function or operator to behave differently based on the context.
- It can be achieved through:
  - **Compile-time Polymorphism**: Achieved through function overloading and operator overloading.
  - **Runtime Polymorphism**: Achieved through virtual functions and inheritance.
  - **Dynamic Binding**: The process of linking a procedure call to the code to be executed
  - **Static Binding**: The process of linking a procedure call to the code to be executed at compile time.

# Function Overloading
- Function overloading allows us to define multiple functions with the same name but different parameter lists.
- The compiler determines which function to call based on the number and type of arguments passed.
- It is a form of compile-time polymorphism.
```cpp
class Math {
public:
    int add(int a, int b) { // Function to add two integers
        return a + b;
    }
    double add(double a, double b) { // Function to add two doubles
        return a + b;
    }
};
int main() {
    Math math;
    cout << "Sum of integers: " << math.add(5, 10) << endl; // Calls integer add function
    cout << "Sum of doubles: " << math.add(5.5, 10.5) << endl; // Calls double add function
    return 0;
}
```
# Operator Overloading
- Operator overloading allows us to redefine the behavior of operators for user-defined types (classes).
- We can overload operators by defining a function with the operator keyword followed by the operator symbol.
- We can overload both unary and binary operators.
```cpp
class Complex {
private:
    int real;
    int imag;
public:
    Complex(int r, int i) : real(r), imag(i) {}
    Complex operator + (const Complex& c) { // Overloading + operator
        return Complex(real + c.real, imag + c.imag);
    }
    void display() {
        cout << "Complex number: " << real << " + " << imag << "i" << endl;
    }
};
int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    Complex c3 = c1 + c2; // Using overloaded + operator
    c3.display(); // Displaying the result
    return 0;
}
```





