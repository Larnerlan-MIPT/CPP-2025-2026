#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
        return 1;

    char *a = argv[1];
    int b = atoi(argv[2]);
    
    for (int i = 0; i < b; i++)
    {
        printf("%s ", a);
    }
    
    return 0;
}