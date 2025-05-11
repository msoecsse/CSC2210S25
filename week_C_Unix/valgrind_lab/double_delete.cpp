#include <iostream>

int main() {
    int* p = new int(99);
    delete p;
    delete p;
    return 0;
}
