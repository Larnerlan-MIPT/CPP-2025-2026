#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *a = fopen(argv[1], "r");
    int n = atoi(argv[2]);
    FILE *b = fopen("result.ppm", "w");
    char c[10];
    int d, e, f;
    fscanf(a, "%s", c);
    fscanf(a, "%d %d", &d, &e);
    fscanf(a, "%d", &f);
    int *g = malloc(d * e * sizeof(int));
    int *h = malloc(d * e * sizeof(int));
    int *j = malloc(d * e * sizeof(int));
    for (int i = 0; i < d * e; i++) {
        fscanf(a, "%d %d %d", &g[i], &h[i], &j[i]);
    }
    fclose(a);
    int *k = malloc(d * e * sizeof(int));
    int *l = malloc(d * e * sizeof(int));
    int *m = malloc(d * e * sizeof(int));
    for (int i = 0; i < d * e; i++) {
        k[i] = g[i];
        l[i] = h[i];
        m[i] = j[i];
    }
    for (int o = 0; o < n; o++) {
        for (int p = 1; p < e-1; p++) {
            for (int q = 1; q < d-1; q++) {
                int r = 0, s = 0, t = 0;
                for (int u = -1; u <= 1; u++) {
                    for (int v = -1; v <= 1; v++) {
                        int w = (p+u)*d + (q+v);
                        r += g[w];
                        s += h[w];
                        t += j[w];
                    }
                }
                k[p*d+q] = r / 9;
                l[p*d+q] = s / 9;
                m[p*d+q] = t / 9;
            }
        }
        for (int i = 0; i < d * e; i++) {
            g[i] = k[i];
            h[i] = l[i];
            j[i] = m[i];
        }
    }
    fprintf(b, "P3\n%d %d\n%d\n", d, e, f);
    for (int i = 0; i < d * e; i++) {
        fprintf(b, "%d %d %d ", g[i], h[i], j[i]);
    }
    fclose(b);
    free(g);
    free(h);
    free(j);
    free(k);
    free(l);
    free(m);
    return 0;
}