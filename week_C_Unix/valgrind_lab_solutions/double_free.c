#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    *p = 123;
    free(p);
    p = NULL; // prevent double free
    return 0;
}
