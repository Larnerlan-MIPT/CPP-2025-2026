// h.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

int main() {
    Book* h = (Book*)malloc(sizeof(Book));
    h->title = (char*)malloc(20 * sizeof(char));
    strcpy(h->title, "Don Quixote");
    h->pages = 1000;
    h->price = 750.0;
    printf("%s %d %.1f\n", h->title, h->pages, h->price);
    free(h->title);
    free(h);
    return 0;
}