#include <stdio.h>
#include "dynarray.h"

DECLARE_LIST(int)
DECLARE_LIST(float)

int main() {
    List_int a;
    list_int_init(&a);
    
    list_int_push_back(&a, 10);
    list_int_push_back(&a, 20);
    list_int_push_front(&a, 5);
    
    int x = list_int_pop_back(&a);
    printf("%d\n", x);
    
    int y = list_int_pop_front(&a);
    printf("%d\n", y);
    
    list_int_clear(&a);
    
    List_float b;
    list_float_init(&b);
    
    list_float_push_back(&b, 1.5f);
    list_float_push_back(&b, 2.5f);
    
    float z = list_float_pop_back(&b);
    printf("%f\n", z);
    
    list_float_clear(&b);
    
    return 0;
}