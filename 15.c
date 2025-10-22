#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int width = 500;
    int height = 500;
    
    int *r = malloc(width * height * sizeof(int));
    int *g = malloc(width * height * sizeof(int));
    int *b = malloc(width * height * sizeof(int));
    
    for (int i = 0; i < width * height; i++) {
        r[i] = 255;
        g[i] = 255;
        b[i] = 255;
    }
    
    srand(time(NULL));
    
    for (int line = 0; line < n; line++) {
        int x0 = rand() % width;
        int y0 = rand() % height;
        int x1 = rand() % width;
        int y1 = rand() % height;
        int rc = rand() % 256;
        int gc = rand() % 256;
        int bc = rand() % 256;
        
        int dx = abs(x1 - x0);
        int dy = abs(y1 - y0);
        int sx = (x0 < x1) ? 1 : -1;
        int sy = (y0 < y1) ? 1 : -1;
        int err = dx - dy;
        
        while (1) {
            if (x0 >= 0 && x0 < width && y0 >= 0 && y0 < height) {
                int idx = y0 * width + x0;
                r[idx] = rc;
                g[idx] = gc;
                b[idx] = bc;
            }
            if (x0 == x1 && y0 == y1) break;
            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x0 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y0 += sy;
            }
        }
    }
    
    FILE *file = fopen("randlines.ppm", "w");
    fprintf(file, "P3\n%d %d\n255\n", width, height);
    for (int i = 0; i < width * height; i++) {
        fprintf(file, "%d %d %d ", r[i], g[i], b[i]);
    }
    fclose(file);
    
    free(r);
    free(g);
    free(b);
    return 0;
}