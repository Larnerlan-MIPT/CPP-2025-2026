// b.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* b = (char*)malloc(9 * sizeof(char));
    strcpy(b, "Elephant");
    printf("%s\n", b);
    free(b);
    return 0;
}