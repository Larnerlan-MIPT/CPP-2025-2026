#include <stdio.h>

int is_palindrom(char a[])
{
    int b = 0;
    int c = 0;
    
    while (a[b] != '\0')
        b++;
    
    b--;
    
    while (c < b)
    {
        if (a[c] != a[b])
            return 0;
        c++;
        b--;
    }
    
    return 1;
}

int main()
{
    char d[100];
    scanf("%s", d);
    
    if (is_palindrom(d))
        printf("Yes\n");
    else
        printf("No\n");
    
    return 0;
}