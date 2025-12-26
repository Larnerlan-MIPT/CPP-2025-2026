#include <stdio.h>
#include <string.h>

int main()
{
    int a;
    char b[10];
    int c;
    int d = 0;
    int e = 0;
    
    scanf("%d", &a);
    
    for (int i = 0; i < a; i++)
    {
        scanf("%s %d", b, &c);
        
        if (strcmp(b, "North") == 0)
            e = e + c;
        else if (strcmp(b, "South") == 0)
            e = e - c;
        else if (strcmp(b, "East") == 0)
            d = d + c;
        else if (strcmp(b, "West") == 0)
            d = d - c;
    }
    
    printf("%d %d", d, e);
    
    return 0;
}