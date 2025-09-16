#include <stdio.h>

float yearfrac(int a, int b)
{
    int days;
    if (a % 4 == 0)
        days = 366;
    else
        days = 365;
    
    return (float)b / days;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.5f\n", yearfrac(a, b));
    return 0;
}