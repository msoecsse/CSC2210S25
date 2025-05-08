#include <stdio.h>
#include <stdlib.h>

void leak() {
    int *arr = malloc(100 * sizeof(int));
    arr[0] = 42;
}

int main() {
    leak();
    return 0;
}
