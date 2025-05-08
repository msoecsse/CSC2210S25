#include <iostream>

int main() {
    int* p = new int(99);
    delete p;
    p = nullptr; // prevent double delete
    return 0;
}
