// f.c
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
    Book** f = (Book**)malloc(sizeof(Book*));
    *f = (Book*)malloc(sizeof(Book));
    strcpy((*f)->title, "Don Quixote");
    (*f)->pages = 1000;
    (*f)->price = 750.0;
    printf("%s %d %.1f\n", (*f)->title, (*f)->pages, (*f)->price);
    free(*f);
    free(f);
    return 0;
}