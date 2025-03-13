#include <iostream>
#include <string>

// ==================================================
// Template function
// ==================================================
template <typename T>
// a template function that returns the maximum of two values
// & allows the compiler to deduce the type of T
//T maxValue(T a, T b) {
T maxValue(const T& a, const T& b) {
    return (a > b) ? a : b; // return a if a > b, otherwise return b
}
// ==================================================
template <typename T1>
T1 minValue(const T1 a , const T1 b) {
    return (a < b) ? a : b; // return a if a < b, otherwise return b
}


int main() {
    // 1) Basic usage with built-in types
    std::cout << "maxValue(3, 7) = "
              << maxValue(3, 7)
              << std::endl;

    std::cout << "maxValue(3.14, 2.72) = "
              << maxValue(3.14, 2.72)
              << std::endl;

    // 2) Usage with std::string
    std::string s1 = "apple";
    std::string s2 = "banana";
    std::cout << "maxValue(s1, s2) = "
              << maxValue(s1, s2)
              << std::endl;


    // 3) Usage with user-defined types (struct)
    // struct is a user-defined type that can be used with templates

    // Structures (also called structs) are a way to group several related variables into one place.
    // Each variable in the structure is known as a member of the structure.

    //Unlike an array, a structure can contain many different data types(int, string, bool, etc.)

    struct Person {
        std::string name;
        int age;
    };

    Person p1 = {"Alice", 30};
    Person p2 = {"Bob", 25};
    std::cout << "maxValue(p1, p2).name = "
              << maxValue(p1, p2).age
              << std::endl;
    std::cout << "maxValue(p1, p2).name = "
              << maxValue(p1, p2).name
              << std::endl;

    //


    // 4) potential pitfall: if T is deduced in an unexpected way
    // For instance, if you try to compare two different types, the
    // compiler may perform implicit conversions, or fail to compile.
    // e.g., maxValue(5, 5.5) forces one type to convert to the other.
    // The result is double in this case, but you might not realize it.
    std::cout << "maxValue(5, 5.5) = "
              << maxValue(5, 5.5)
              << std::endl;

    return 0;
}
