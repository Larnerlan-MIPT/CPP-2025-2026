// a.c
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t* a = (size_t*)malloc(sizeof(size_t));
    *a = 123;
    printf("%zu\n", *a);
    free(a);
    return 0;
}