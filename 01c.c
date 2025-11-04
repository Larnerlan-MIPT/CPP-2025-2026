// c.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* c_str = (char*)malloc(14 * sizeof(char));
    strcpy(c_str, "Cats and Dogs");
    char** c = (char**)malloc(sizeof(char*));
    *c = c_str;
    printf("%s\n", *c);
    free(c_str);
    free(c);
    return 0;
}