#include "dynarray.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Dynarray arr;
    arr.size = 3;
    arr.capacity = 5;
    arr.data = malloc(5 * sizeof(int));
    arr.data[0] = 10;
    arr.data[1] = 20;
    arr.data[2] = 30;

    int a = pop_back(&arr);
    printf("%d\n", a);

    resize(&arr, 4);
    printf("%zu\n", arr.size);

    shrink_to_fit(&arr);
    printf("%zu\n", arr.capacity);

    Dynarray b = shallow_copy(&arr);
    printf("%p\n", b.data);

    Dynarray c = deep_copy(&arr);
    printf("%p\n", c.data);

    free(arr.data);
    free(c.data);
    return 0;
}