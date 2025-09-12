#include <stdio.h>

int sum(int x) {
    int s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int a[10000];
    int b[10000];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = sum(a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
                t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}