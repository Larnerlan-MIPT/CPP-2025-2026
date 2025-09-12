#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int s = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int a = 1;
            if ((i + j) % 2 == 1) {
                a = -1;
            }
            s += a * i * j;
        }
    }
    
    printf("%d", s);
    
    return 0;
}