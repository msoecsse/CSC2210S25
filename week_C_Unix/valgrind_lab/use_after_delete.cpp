#include <iostream>

int main() {
    int* p = new int(42);
    delete p;
    std::cout << *p << std::endl;
    return 0;
}
