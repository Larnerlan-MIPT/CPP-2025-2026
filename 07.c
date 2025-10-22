#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *a = fopen(argv[1], "rb");
    fseek(a, 0, SEEK_END);
    long b = ftell(a);
    printf("%ld\n", b);
    fclose(a);
    return 0;
}