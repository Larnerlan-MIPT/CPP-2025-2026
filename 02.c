#include <stdio.h>
#include <stdlib.h>

float* get_geometric_progression(float a, float r, int n) {
    float* p = (float*)malloc(n * sizeof(float));
    p[0] = a;
    for (int i = 1; i < n; i++) {
        p[i] = p[i-1] * r;
    }
    return p;
}

int main() {
    float a, r;
    int n;
    scanf("%f %f %d", &a, &r, &n);
    
    float* g = get_geometric_progression(a, r, n);
    
    for (int i = 0; i < 10; i++) {
        printf("%f ", g[i]);
    }
    
    free(g);
    return 0;
}