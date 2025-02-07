// // function pointers
/
#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

void mystery(int x, int y, int (*fn)(int, int)) // function pointer as a parameter
{
    std::cout << "The result is: " << fn(x, y) << std::endl; // calling the function pointer
}


int main()
{
    int a = 10;
    int b = 20;
    int result;

    void (*fptr)(int, int, int (*)(int, int)) = mystery; // function pointer
    // the above line points to the mystery function



    fptr(a, b, add);
    // display the memory address of the add function
    fptr(a, b, subtract);

    fptr(a, b, multiply);
    fptr(a, b, divide);
    // Display the memory addresses of the add and subtract functions
    std::cout << "Address of add function:       " << reinterpret_cast<void*>(add) << std::endl;
    std::cout << "Address of subtract function:  " << reinterpret_cast<void*>(subtract) << std::endl;
    return 0;
}

