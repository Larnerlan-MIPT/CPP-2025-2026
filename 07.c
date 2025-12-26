#include <stdio.h>

void encrypt(char* a, int b)
{
    int c = 0;
    
    while (a[c] != '\0')
    {
        if (a[c] >= 'A' && a[c] <= 'Z')
        {
            a[c] = 'A' + (a[c] - 'A' + b) % 26;
        }
        else if (a[c] >= 'a' && a[c] <= 'z')
        {
            a[c] = 'a' + (a[c] - 'a' + b) % 26;
        }
        c++;
    }
}

int main()
{
    char d[100];
    int e;
    
    scanf("%d %[^\n]", &e, d);
    
    encrypt(d, e);
    printf("%s", d);
    
    return 0;
}