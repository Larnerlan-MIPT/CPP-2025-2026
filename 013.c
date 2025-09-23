#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: ./calc <number> <operator> <number>\n");
        return 1;
    }

    char *a = argv[1];
    char *b = argv[2];
    char *c = argv[3];
    
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] < '0' || a[i] > '9')
        {
            printf("Error: Operands should be integers!\n");
            return 1;
        }
    }
    
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] < '0' || c[i] > '9')
        {
            printf("Error: Operands should be integers!\n");
            return 1;
        }
    }
    
    int d = atoi(a);
    int e = atoi(c);
    
    if (b[0] == '+')
        printf("%d\n", d + e);
    else if (b[0] == '-')
        printf("%d\n", d - e);
    else if (b[0] == '*')
        printf("%d\n", d * e);
    else if (b[0] == '/')
    {
        if (e == 0)
        {
            printf("Error: Division by zero!\n");
            return 1;
        }
        printf("%d\n", d / e);
    }
    else if (b[0] == '%')
        printf("%d\n", d % e);
    else
    {
        printf("Error: Invalid operator!\n");
        return 1;
    }
    
    return 0;
}