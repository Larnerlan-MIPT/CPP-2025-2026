#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *a = fopen(argv[1], "r");
    FILE *b = fopen("result.ppm", "w");
    char c[10];
    int d, e, f;
    fscanf(a, "%s", c);
    fscanf(a, "%d %d", &d, &e);
    fscanf(a, "%d", &f);
    fprintf(b, "P3\n%d %d\n%d\n", d, e, f);
    for (int i = 0; i < d * e; i++) {
        int g, h, j;
        fscanf(a, "%d %d %d", &g, &h, &j);
        int k = 0.393 * g + 0.769 * h + 0.189 * j;
        int l = 0.349 * g + 0.686 * h + 0.168 * j;
        int m = 0.272 * g + 0.534 * h + 0.131 * j;
        if (k > 255) k = 255;
        if (l > 255) l = 255;
        if (m > 255) m = 255;
        fprintf(b, "%d %d %d ", k, l, m);
    }
    fclose(a);
    fclose(b);
    return 0;
}