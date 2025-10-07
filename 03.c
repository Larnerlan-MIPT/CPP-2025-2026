#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char* a, const char* b) {
    char* c = (char*)malloc((strlen(a) + strlen(b) + 1) * sizeof(char));
    strcpy(c, a);
    strcat(c, b);
    return c;
}

int main() {
    char a[100], b[100];
    scanf("%s %s", a, b);
    
    char* result = concat(a, b);
    printf("%s", result);
    
    free(result);
    return 0;
}