#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    unsigned char r, g, b;
} Color;

void draw_circle(Color* data, int width, int height, int x0, int y0, int r, Color c) {
    for (int y = y0 - r; y <= y0 + r; y++) {
        if (y < 0 || y >= height) continue;
        for (int x = x0 - r; x <= x0 + r; x++) {
            if (x < 0 || x >= width) continue;
            int dx = x - x0;
            int dy = y - y0;
            if (dx * dx + dy * dy <= r * r) {
                data[y * width + x] = c;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int width = 600;
    int height = 400;
    
    Color *data = malloc(width * height * sizeof(Color));
    for (int i = 0; i < width * height; i++) {
        data[i].r = 255;
        data[i].g = 255;
        data[i].b = 255;
    }
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int x0 = rand() % width;
        int y0 = rand() % height;
        int r = a + rand() % (b - a + 1);
        Color c = {rand() % 256, rand() % 256, rand() % 256};
        draw_circle(data, width, height, x0, y0, r, c);
    }
    
    FILE *file = fopen("circles.ppm", "w");
    fprintf(file, "P3\n%d %d\n255\n", width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Color pixel = data[y * width + x];
            fprintf(file, "%d %d %d ", pixel.r, pixel.g, pixel.b);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    
    free(data);
    return 0;
}