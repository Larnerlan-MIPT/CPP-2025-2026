#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 4) return 1;
    
    char *effect = argv[1];
    char *input = argv[argc-2];
    char *output = argv[argc-1];
    
    FILE *a = fopen(input, "r");
    FILE *b = fopen(output, "w");
    
    char c[10];
    int d, e, f;
    fscanf(a, "%s", c);
    fscanf(a, "%d %d", &d, &e);
    fscanf(a, "%d", &f);
    
    int *g = malloc(d * e * 3 * sizeof(int));
    for (int i = 0; i < d * e; i++) {
        fscanf(a, "%d %d %d", &g[i*3], &g[i*3+1], &g[i*3+2]);
    }
    fclose(a);
    
    if (strcmp(effect, "--sepia") == 0) {
        for (int i = 0; i < d * e; i++) {
            int h = g[i*3];
            int j = g[i*3+1];
            int k = g[i*3+2];
            int l = 0.393 * h + 0.769 * j + 0.189 * k;
            int m = 0.349 * h + 0.686 * j + 0.168 * k;
            int n = 0.272 * h + 0.534 * j + 0.131 * k;
            if (l > 255) l = 255;
            if (m > 255) m = 255;
            if (n > 255) n = 255;
            g[i*3] = l;
            g[i*3+1] = m;
            g[i*3+2] = n;
        }
    }
    else if (strcmp(effect, "--blur") == 0) {
        int o = atoi(argv[2]);
        int *p = malloc(d * e * 3 * sizeof(int));
        for (int q = 0; q < o; q++) {
            for (int r = 0; r < d * e; r++) {
                p[r*3] = g[r*3];
                p[r*3+1] = g[r*3+1];
                p[r*3+2] = g[r*3+2];
            }
            for (int s = 1; s < e-1; s++) {
                for (int t = 1; t < d-1; t++) {
                    int u = 0, v = 0, w = 0;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            int z = (s+y)*d + (t+x);
                            u += p[z*3];
                            v += p[z*3+1];
                            w += p[z*3+2];
                        }
                    }
                    g[s*d*3 + t*3] = u / 9;
                    g[s*d*3 + t*3+1] = v / 9;
                    g[s*d*3 + t*3+2] = w / 9;
                }
            }
        }
        free(p);
    }
    else if (strcmp(effect, "--brighter") == 0) {
        int aa = atoi(argv[2]);
        for (int i = 0; i < d * e * 3; i++) {
            g[i] += aa;
            if (g[i] > 255) g[i] = 255;
        }
    }
    else if (strcmp(effect, "--bw") == 0) {
        for (int i = 0; i < d * e; i++) {
            int ab = 0.299 * g[i*3] + 0.587 * g[i*3+1] + 0.114 * g[i*3+2];
            g[i*3] = ab;
            g[i*3+1] = ab;
            g[i*3+2] = ab;
        }
    }
    else if (strcmp(effect, "--changecolors") == 0) {
        for (int i = 0; i < d * e; i++) {
            int ac = g[i*3];
            g[i*3] = g[i*3+2];
            g[i*3+2] = ac;
        }
    }
    else if (strcmp(effect, "--mirror") == 0) {
        for (int s = 0; s < e; s++) {
            for (int t = 0; t < d/2; t++) {
                int ad = s*d + t;
                int ae = s*d + (d-1-t);
                for (int af = 0; af < 3; af++) {
                    int ag = g[ad*3+af];
                    g[ad*3+af] = g[ae*3+af];
                    g[ae*3+af] = ag;
                }
            }
        }
    }
    
    fprintf(b, "P3\n%d %d\n%d\n", d, e, f);
    for (int i = 0; i < d * e; i++) {
        fprintf(b, "%d %d %d ", g[i*3], g[i*3+1], g[i*3+2]);
    }
    fclose(b);
    free(g);
    return 0;
}