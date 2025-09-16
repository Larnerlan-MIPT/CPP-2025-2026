#include <stdio.h>
#include <stdint.h>

int main()
{
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(long long));
    printf("%lu\n", sizeof(int32_t));
    printf("%lu\n", sizeof(double));
    printf("%lu\n", sizeof(short));
    printf("%lu\n", sizeof(size_t));
    printf("%lu\n", sizeof(uint32_t));
    printf("%lu\n", sizeof(int[100]));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(int8_t));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(char[100]));
    
    return 0;
}