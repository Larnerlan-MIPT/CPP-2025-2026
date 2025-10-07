#include <stdio.h>
#include <stdlib.h>

int a;
int b = 10;
const int c = 20;
void f()
{
    printf("hello f\n");
}

int main()
{
    int d;
    static int e;

    int* pi = (int*)malloc(sizeof(int) * 10);

    const char s[] = "cat";
    const char* ps = "dog";

    printf("&a = %p\n", &a);
    printf("&b = %p\n", &b);
    printf("&c = %p\n", &c);
    printf("&d = %p\n", &d);
    printf("&e = %p\n", &e);
    printf("&pi = %p\n", &pi);
    printf("pi = %p\n", pi);
    printf("pi+5 = %p\n", pi + 5);
    printf("&s = %p\n", &s);
    printf("s = %p\n", s);
    printf("&ps = %p\n", &ps);
    printf("ps = %p\n", ps);
    printf("f = %p\n", f);
    printf("&f = %p\n", &f);
    printf("main = %p\n", main);
    printf("\"fox\" = %p\n", "fox");

    free(pi);
}