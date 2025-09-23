#include <stdio.h>
int main()
{
    char a[100];
    char b[100];
    int i = 0;
    
    scanf("%s %s", a, b);
    
    while (a[i] != '\0' || b[i] != '\0')
    {
        if (a[i] != '\0')
            printf("%c", a[i]);
        if (b[i] != '\0')
            printf("%c", b[i]);
        i++;
    }
    
    return 0;
}