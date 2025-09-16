#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, d, e, f;
    scanf("%lf %lf %lf", &a, &b, &c);
    scanf("%lf %lf %lf", &d, &e, &f);
    
    double x = d - a;
    double y = e - b;
    double dist = sqrt(x * x + y * y);
    
    double r_sum = c + f;
    double r_diff = fabs(c - f);
    
    if (dist > r_sum)
        printf("Do not intersect\n");
    else if (fabs(dist - r_sum) < 0.00001 || fabs(dist - r_diff) < 0.00001)
        printf("Touch\n");
    else
        printf("Intersect\n");
        
    return 0;
}