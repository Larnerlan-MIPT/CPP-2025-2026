#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int width = 500;
    int height = 500;
    double k = 255.0;
    
    for (int func = 1; func <= 5; func++) {
        char filename[20];
        sprintf(filename, "function%d.ppm", func);
        FILE *file = fopen(filename, "w");
        fprintf(file, "P3\n%d %d\n255\n", width, height);
        
        for (int j = 0; j < height; j++) {
            for (int i = 0; i < width; i++) {
                double x = (i - 250) / 250.0;
                double y = (j - 250) / 250.0;
                double value = 0;
                
                if (func == 1) value = fabs(x * y);
                else if (func == 2) value = fabs(sin(10 * (x*x + y*y)));
                else if (func == 3) value = fabs(sin(5000 * (x*x + y*y)));
                else if (func == 4) value = fabs(cos(10*x) * sin(10*y));
                else if (func == 5) value = 0.5 * fabs(sin(3/(0.1+fabs(x))) + sin(3/(0.1+fabs(y))));
                
                int intensity = (int)(k * value);
                if (intensity > 255) intensity = 255;
                fprintf(file, "%d %d %d ", intensity, intensity, intensity);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
    
    return 0;
}