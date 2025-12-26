#include <math.h>
#include <stdio.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
    double d = b * b - 4 * a * c;
    
    if (d < -1e-10)
        return 0;
    
    if (fabs(d) < 1e-10) {
        *px1 = -b / (2 * a);
        return 1;
    }
    
    *px1 = (-b - sqrt(d)) / (2 * a);
    *px2 = (-b + sqrt(d)) / (2 * a);
    return 2;
}

int main()
{
    double a, b, c;
    double x1, x2;
    
    scanf("%lf %lf %lf", &a, &b, &c);
    
    int roots = solve_quadratic(a, b, c, &x1, &x2);
    return 0;
}