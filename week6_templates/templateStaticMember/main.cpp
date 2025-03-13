#include <iostream>

using namespace std;
//
// template <typename T>
// function with a static variable
// void fun(const T& x)
// {
// static int i = 10;
// cout << ++i;
// return;
// }
//
// int main()
// {
// fun<int>(1); // prints 11
// cout << endl;
// fun<int>(2); // prints 12
// cout << endl;
// fun<double>(1.1); // prints 11 10+1=11 instead of 11.1
// cout << endl;
// return 0;
// }

#include <iostream>

// A class template with a static data member
template <typename T>
class MyClass {
public:
    static int count;  // Declaration of static member

    MyClass() { ++count; }
};

// Definition of the static member
template <typename T>
int MyClass<T>::count = 0;

int main() {
    MyClass<int> obj1;
    MyClass<int> obj2;
    MyClass<double> obj3;

    std::cout << "count<int>:    " << MyClass<int>::count << "\n";
    std::cout << "count<double>: " << MyClass<double>::count << "\n";

    return 0;
}
