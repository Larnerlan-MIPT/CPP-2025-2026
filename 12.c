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
        fprintf(b, "%d %d %d ", j, h, g);
    }
    fclose(a);
    fclose(b);
    return 0;
}