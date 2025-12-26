#include <stdio.h>
int main()
{
    char a;
    char b[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char c[] = "0123456789";
    int d = 0;
    int i = 0;
    
    scanf("%c", &a);
    
    while (b[i] != '\0')
    {
        if (a == b[i])
            d = 1;
        i++;
    }
    
    i = 0;
    while (c[i] != '\0')
    {
        if (a == c[i])
            d = 2;
        i++;
    }
    
    if (d == 1)
        printf("Letter\n");
    else if (d == 2)
        printf("Digit\n");
    else
        printf("Other\n");
    
    return 0;
}
