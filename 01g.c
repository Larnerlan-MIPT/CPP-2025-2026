// g.c
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
    Book* g = (Book*)malloc(3 * sizeof(Book));
    strcpy(g[0].title, "Don Quixote");
    g[0].pages = 1000;
    g[0].price = 750.0;
    strcpy(g[1].title, "Oblomov");
    g[1].pages = 400;
    g[1].price = 250.0;
    strcpy(g[2].title, "The Odyssey");
    g[2].pages = 500;
    g[2].price = 500.0;
    for (int i = 0; i < 3; i++) {
        printf("%s %d %.1f\n", g[i].title, g[i].pages, g[i].price);
    }
    free(g);
    return 0;
}