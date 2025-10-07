// i.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char* title;
    int pages;
    float price;
};
typedef struct book Book;

struct library {
    Book* books;
    int number_of_books;
};
typedef struct library Library;

void library_create(Library* lib, int n) {
    lib->number_of_books = n;
    lib->books = (Book*)malloc(n * sizeof(Book));
}

void library_set(Library* lib, int index, char* title, int pages, float price) {
    lib->books[index].title = (char*)malloc((strlen(title) + 1) * sizeof(char));
    strcpy(lib->books[index].title, title);
    lib->books[index].pages = pages;
    lib->books[index].price = price;
}

Book* library_get(Library* lib, int index) {
    return &lib->books[index];
}

void print_book(Book* b) {
    printf("%s %d %.2f\n", b->title, b->pages, b->price);
}

void library_print(Library* lib) {
    for (int i = 0; i < lib->number_of_books; i++) {
        print_book(&lib->books[i]);
    }
}

void library_destroy(Library* lib) {
    for (int i = 0; i < lib->number_of_books; i++) {
        free(lib->books[i].title);
    }
    free(lib->books);
    lib->books = NULL;
    lib->number_of_books = 0;
}

int main() {
    Library a;
    library_create(&a, 3);
    library_set(&a, 0, "Don Quixote", 1000, 750.0);
    library_set(&a, 1, "Oblomov", 400, 250.0);
    library_set(&a, 2, "The Odyssey", 500, 500.0);
    library_print(&a);
    print_book(library_get(&a, 1));
    library_destroy(&a);
    return 0;
}