#include <stdlib.h>

void memory_leak_example() {
    // Allocate memory without freeing it
    int* numbers = (int*)malloc(sizeof(int) * 10);
    // numbers pointer is lost without calling free()

    // Access the allocated memory
    for (int i = 0; i < 10; i++) {
        numbers[i] = i;
    }
}

int main() {
    memory_leak_example();

    return 0;
}