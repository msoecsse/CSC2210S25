#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    *p = 123;
    free(p);
    free(p);
    return 0;
}
