#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int *c = (int*)malloc(a * sizeof(int));
    for (int d = 0; d < a; ++d) {
        c[d] = d + 1;
    }

    int e = 0;
    int f = a;
    while (f > 1) {
        e = (e + b - 1) % f;
        printf("%d ", c[e]);
        for (int g = e; g < f - 1; ++g) {
            c[g] = c[g + 1];
        }
        f--;
    }

    printf("\n%d\n", c[0]);

    free(c);
    return 0;
}