#include <stdio.h>

void print_binary(int n)
{
    if (n > 1)
        print_binary(n / 2);
    printf("%d", n % 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    print_binary(n);
    return 0;
}