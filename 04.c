#include <stdio.h>

void mult2a(int* p, size_t n)
{
    for (size_t i = 0; i < n; i++)
        *(p + i) = *(p + i) * 2;
}

void mult2b(int* p, size_t n)
{
    for (size_t i = 0; i < n; i++)
        p[i] = p[i] * 2;
}

int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
        scanf("%d", &a[i]);
    
    mult2a(a, 5);
    
    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);
    
    return 0;
}