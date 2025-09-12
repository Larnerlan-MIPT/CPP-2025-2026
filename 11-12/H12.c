#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[10][10], b[10][10], c[10][10] = {0};
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
            
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
            
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
                
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
    
    return 0;
}