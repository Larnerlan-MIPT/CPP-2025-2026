#include "dynarray.h"
#include <stdlib.h>
#include <stdio.h>

int pop_back(Dynarray* pd) {
    if (pd->size == 0) {
        printf("Error\n");
        exit(1);
    }
    pd->size--;
    return pd->data[pd->size];
}

void resize(Dynarray* pd, size_t new_size) {
    if (new_size > pd->capacity) {
        pd->data = realloc(pd->data, new_size * sizeof(int));
        for (size_t i = pd->size; i < new_size; i++) {
            pd->data[i] = 0;
        }
        pd->capacity = new_size;
    }
    pd->size = new_size;
}

void shrink_to_fit(Dynarray* pd) {
    pd->data = realloc(pd->data, pd->size * sizeof(int));
    pd->capacity = pd->size;
}

Dynarray shallow_copy(Dynarray* pd) {
    Dynarray a;
    a.data = pd->data;
    a.size = pd->size;
    a.capacity = pd->capacity;
    return a;
}

Dynarray deep_copy(const Dynarray* pd) {
    Dynarray a;
    a.data = malloc(pd->size * sizeof(int));
    for (size_t i = 0; i < pd->size; i++) {
        a.data[i] = pd->data[i];
    }
    a.size = pd->size;
    a.capacity = pd->size;
    return a;
}