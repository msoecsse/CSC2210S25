#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    *p = 100;
    free(p);
    *p = 200;
    printf("%d\n", *p);
    return 0;
}
