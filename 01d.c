// d.c
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
    Book* d = (Book*)malloc(sizeof(Book));
    strcpy(d->title, "Don Quixote");
    d->pages = 1000;
    d->price = 750.0;
    printf("%s %d %.1f\n", d->title, d->pages, d->price);
    free(d);
    return 0;
}