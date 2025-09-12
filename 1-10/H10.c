#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int a[m];
    for (int i = 0; i < m; i++) {
        a[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int b;
            scanf("%d", &b);
            a[j] += b;
        }
    }
    
    for (int i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}