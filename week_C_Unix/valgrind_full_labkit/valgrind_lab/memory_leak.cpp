#include <iostream>
void leak() {
    int* p = new int[100];
    p[0] = 55;
}
int main() {
    leak();
    return 0;
}