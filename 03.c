#include <stdio.h>
#include <string.h>

int main()
{
    int a[4] = {1819043144, 1461726319, 1684828783, 2593};
    
    char* b = (char*)a;
    for(int i = 0; i < 16; i++)
    {
        if(b[i] >= 32 && b[i] <= 126) printf("%c", b[i]);
        else printf(".");
    }
    printf("\n");
    
    union
    {
        int c[4];
        char d[16];
    } u;
    u.c[0] = a[0];
    u.c[1] = a[1];
    u.c[2] = a[2];
    u.c[3] = a[3];
    for(int i = 0; i < 16; i++)
    {
        if(u.d[i] >= 32 && u.d[i] <= 126) printf("%c", u.d[i]);
        else printf(".");
    }
    printf("\n");
    
    char e[16];
    memcpy(e, a, 16);
    for(int i = 0; i < 16; i++)
    {
        if(e[i] >= 32 && e[i] <= 126) printf("%c", e[i]);
        else printf(".");
    }
    printf("\n");
    
    return 0;
}