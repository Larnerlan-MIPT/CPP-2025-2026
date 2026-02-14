#include <stdio.h>
#include <math.h>

double gamma(double x)
{
    double step = 0.01;
    double eps = 0.0000000001;
    double sum = 0.0;
    double t = 0.0;
    
    while (1)
    {
        double f1 = pow(t, x-1) * exp(-t);
        double f2 = pow(t+step, x-1) * exp(-(t+step));
        double area = (f1 + f2) * step / 2;
        
        if (area < eps && t > 100)
            break;
            
        sum += area;
        t += step;
    }
    
    return sum;
}

int main()
{
    double a;
    scanf("%lf", &a);
    printf("%.5f\n", gamma(a));
    return 0;
}