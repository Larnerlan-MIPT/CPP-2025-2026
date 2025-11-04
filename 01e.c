// e.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

int main() {
    Book e_stack;
    strcpy(e_stack.title, "Don Quixote");
    e_stack.pages = 1000;
    e_stack.price = 750.0;
    Book** e = (Book**)malloc(sizeof(Book*));
    *e = &e_stack;
    printf("%s %d %.1f\n", (*e)->title, (*e)->pages, (*e)->price);
    free(e);
    return 0;
}