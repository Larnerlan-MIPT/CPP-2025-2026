#include <stdio.h>
int main()
{
    int a = 32;
    int b = 126;
    
    while (a <= b)
    {
        printf("Symbol = %c, Code = %d\n", a, a);
        a = a + 1;
    }
    
    return 0;
}