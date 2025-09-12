#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        printf("%3i -> %3i -> %4i\n", i, i * i, i * i * i);
    }
    
    return 0;
}