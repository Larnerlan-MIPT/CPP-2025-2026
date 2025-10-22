#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tree(int x, int y, double angle, int length, int depth, int* r, int* g, int* b, int width, int height) {
    if (depth == 0) return;
    
    int x2 = x + length * cos(angle);
    int y2 = y + length * sin(angle);
    
    if (x2 >= 0 && x2 < width && y2 >= 0 && y2 < height) {
        int dx = abs(x2 - x);
        int dy = abs(y2 - y);
        int sx = (x < x2) ? 1 : -1;
        int sy = (y < y2) ? 1 : -1;
        int err = dx - dy;
        
        int x0 = x, y0 = y;
        while (1) {
            int idx = y0 * width + x0;
            r[idx] = 0;
            g[idx] = 0;
            b[idx] = 0;
            if (x0 == x2 && y0 == y2) break;
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
    
    tree(x2, y2, angle - 0.5235987755982988, length*0.7, depth-1, r, g, b, width, height);
    tree(x2, y2, angle + 0.5235987755982988, length*0.7, depth-1, r, g, b, width, height);
}

int main() {
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
    
    tree(width/2, height-1, -1.5707963267948966, 100, 8, r, g, b, width, height);
    
    FILE *file = fopen("tree.ppm", "w");
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