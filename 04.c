#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    double sum = 0.0;
    int sign = 1;
    
    for (int i = 1; i <= n; i++)
    {
        double term = 1.0 / (2 * i - 1);
        sum += sign * term;
        sign = -sign;
    }
    
    double pi = 4 * sum;
    printf("%f\n", pi);
    
    return 0;
}