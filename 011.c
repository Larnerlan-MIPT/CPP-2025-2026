#include <stdio.h>

void safe_strcpy(char a[], size_t b, const char c[])
{
    size_t d = 0;
    
    while (d < b - 1 && c[d] != '\0')
    {
        a[d] = c[d];
        d++;
    }
    
    a[d] = '\0';
}

int main()
{
    char e[10] = "Mouse";
    char f[50] = "LargeElephant";
    
    safe_strcpy(e, 10, f);
    printf("%s\n", e);
    
    return 0;
}