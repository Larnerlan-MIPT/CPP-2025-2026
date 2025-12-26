#include <stdio.h>
int main()
{
    char a;
    int b = 0;
    
    while (scanf("%c", &a) == 1)
    {
        if (a >= '0' && a <= '9')
            b = b + (a - '0');
    }
    
    printf("%d", b);
    
    return 0;
}