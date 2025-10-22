#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void save_numbers_text(const char* filename, double* array, int n)
{
    FILE* a = fopen(filename, "w");
    fprintf(a, "%d\n", n);
    for(int i = 0; i < n; i++) fprintf(a, "%.15f\n", array[i]);
    fclose(a);
}

void save_numbers_binary(const char* filename, double* array, int n)
{
    FILE* b = fopen(filename, "wb");
    fwrite(&n, sizeof(int), 1, b);
    fwrite(array, sizeof(double), n, b);
    fclose(b);
}

int main()
{
    int n = 1000;
    double* array = (double*)malloc(n * sizeof(double));
    double pi = 3.14159265358979323846;
    for(int i = 0; i < n; i++) array[i] = sin(pi * i / n);
    
    save_numbers_text("numbers.txt", array, n);
    save_numbers_binary("numbers.bin", array, n);
    
    free(array);
    return 0;
}