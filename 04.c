#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** get_test_strings() {
    char** a = (char**)malloc(4 * sizeof(char*));
    a[0] = (char*)malloc(4 * sizeof(char));
    strcpy(a[0], "Cat");
    a[1] = (char*)malloc(9 * sizeof(char));
    strcpy(a[1], "Elephant");
    a[2] = (char*)malloc(6 * sizeof(char));
    strcpy(a[2], "Mouse");
    a[3] = NULL;
    return a;
}

void print_strings(const char** a) {
    for (int i = 0; a[i] != NULL; i++) {
        printf("%s\n", a[i]);
    }
}

size_t* get_sizes(const char** a) {
    int n = 0;
    while (a[n] != NULL) n++;
    
    size_t* b = (size_t*)malloc(n * sizeof(size_t));
    for (int i = 0; i < n; i++) {
        b[i] = strlen(a[i]);
    }
    return b;
}

char** load_lines(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) return NULL;
    
    int n = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') n++;
    }
    n++;
    
    fseek(file, 0, SEEK_SET);
    
    int* lengths = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        lengths[i] = 0;
        while ((c = fgetc(file)) != EOF && c != '\n') {
            lengths[i]++;
        }
    }
    
    fseek(file, 0, SEEK_SET);
    
    char** a = (char**)malloc((n + 1) * sizeof(char*));
    for (int i = 0; i < n; i++) {
        a[i] = (char*)malloc((lengths[i] + 1) * sizeof(char));
        for (int j = 0; j < lengths[i]; j++) {
            a[i][j] = fgetc(file);
        }
        a[i][lengths[i]] = '\0';
        if (i != n - 1) fgetc(file);
    }
    a[n] = NULL;
    
    free(lengths);
    fclose(file);
    return a;
}

void destroy_strings(char*** a) {
    for (int i = 0; (*a)[i] != NULL; i++) {
        free((*a)[i]);
    }
    free(*a);
    *a = NULL;
}

void sort_strings(char** a) {
    int n = 0;
    while (a[n] != NULL) n++;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(a[j], a[j + 1]) > 0) {
                char* temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 3) return 1;
    
    char** a = load_lines(argv[1]);
    if (a == NULL) return 1;
    
    sort_strings(a);
    
    FILE* file = fopen(argv[2], "w");
    if (file == NULL) {
        destroy_strings(&a);
        return 1;
    }
    
    for (int i = 0; a[i] != NULL; i++) {
        fprintf(file, "%s\n", a[i]);
    }
    
    fclose(file);
    destroy_strings(&a);
    return 0;
}