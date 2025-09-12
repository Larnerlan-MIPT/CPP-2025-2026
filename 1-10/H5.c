#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    
    int b = 1;
    int c = a;
    long long d = a;
    
    printf("%lld", d);
    
    while (d != 1) {
        if (d % 2 == 1) {
            d = 3 * d + 1;
        } else {
            d = d / 2;
        }
        
        printf(" %lld", d);
        
        if (d > c) {
            c = d;
        }
        
        b++;
    }
    
    printf("\nLength = %d, Max = %d\n", b, c);
    
    return 0;
}