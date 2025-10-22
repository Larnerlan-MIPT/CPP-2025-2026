#include <stdio.h>

int is_little_endian()
{
    int a = 1;
    char* b = (char*)&a;
    return *b;
}

int main()
{
    return 0;
}