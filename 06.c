#include <stdio.h>

int main()
{
    int a;
    while((a = getchar()) != EOF)
    {
        if(a >= 'A' && a <= 'Z') a = (a - 'A' + 1) % 26 + 'A';
        else if(a >= 'a' && a <= 'z') a = (a - 'a' + 1) % 26 + 'a';
        putchar(a);
    }
    return 0;
}