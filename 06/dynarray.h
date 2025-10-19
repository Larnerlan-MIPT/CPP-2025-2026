#pragma once
#include <stdlib.h>
#include <assert.h>

#define DECLARE_LIST(type) \
struct node_##type { \
    type data; \
    struct node_##type* next; \
    struct node_##type* prev; \
}; \
\
struct list_##type { \
    struct node_##type* head; \
    struct node_##type* tail; \
    size_t size; \
}; \
typedef struct list_##type List_##type; \
\
void list_##type##_init(List_##type* list) { \
    list->head = NULL; \
    list->tail = NULL; \
    list->size = 0; \
} \
\
void list_##type##_push_back(List_##type* list, type value) { \
    struct node_##type* new_node = malloc(sizeof(struct node_##type)); \
    new_node->data = value; \
    new_node->next = NULL; \
    new_node->prev = list->tail; \
    \
    if (list->tail) { \
        list->tail->next = new_node; \
    } else { \
        list->head = new_node; \
    } \
    list->tail = new_node; \
    list->size++; \
} \
\
type list_##type##_pop_back(List_##type* list) { \
    assert(list->size > 0); \
    struct node_##type* node = list->tail; \
    type value = node->data; \
    \
    list->tail = node->prev; \
    if (list->tail) { \
        list->tail->next = NULL; \
    } else { \
        list->head = NULL; \
    } \
    \
    free(node); \
    list->size--; \
    return value; \
} \
\
void list_##type##_push_front(List_##type* list, type value) { \
    struct node_##type* new_node = malloc(sizeof(struct node_##type)); \
    new_node->data = value; \
    new_node->prev = NULL; \
    new_node->next = list->head; \
    \
    if (list->head) { \
        list->head->prev = new_node; \
    } else { \
        list->tail = new_node; \
    } \
    list->head = new_node; \
    list->size++; \
} \
\
type list_##type##_pop_front(List_##type* list) { \
    assert(list->size > 0); \
    struct node_##type* node = list->head; \
    type value = node->data; \
    \
    list->head = node->next; \
    if (list->head) { \
        list->head->prev = NULL; \
    } else { \
        list->tail = NULL; \
    } \
    \
    free(node); \
    list->size--; \
    return value; \
} \
\
void list_##type##_clear(List_##type* list) { \
    struct node_##type* current = list->head; \
    while (current) { \
        struct node_##type* next = current->next; \
        free(current); \
        current = next; \
    } \
    list->head = NULL; \
    list->tail = NULL; \
    list->size = 0; \
}