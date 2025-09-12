// Задача 1
#include <stdio.h>
int main()
{
    printf("Hello World\n");
    return 0;
}

// Задача 2
#include <stdio.h>
int main()
{
    int a = 0;
    scanf("%i", &a);
    printf("%i\n", a * a);
    return 0;
}

// Задача 3
#include <stdio.h>
int main()
{
    int a;
    scanf("%i", &a);
    if (a == 10)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

// Задача 4
#include <stdio.h>
int main()
{
    int a = 0;
    scanf("%i", &a);
    printf("%i\n", a * a);
    return 0;
}

// Задача 5
#include <stdio.h>
int main()
{
    int a;
    scanf("%i", &a);
    if (a > 0) {
        printf("%i\n", a);
        printf("Positive\n");
    }
    return 0;
}

// Задача 6
#include <stdio.h>
int main()
{
    int a;
    scanf("%i", &a);
    if (a > 0)
        printf("Positive\n");
    return 0;
}

// Задача 7
#include <stdio.h>
int main()
{
    int i = 1;
    while (i <= 10) {
        printf("%i ", i);
        i += 1;
    }
    printf("\n");
    return 0;
}

// Задача 8
#include <stdio.h>
int main()
{
    int i = 1;
    while (i <= 10) {
        printf("%i ", i);
        i += 1;
    }
    printf("\n");
    return 0;
}

// Задача 9
#include <stdio.h>
int main()
{
    int n;
    scanf("%i", &n);
    int i = 1;
    int sum = 0;
    while (i <= n) {
        sum += i;
        i += 1;
    }
    printf("%i\n", sum);
    return 0;
}

// Задача 10
#include <stdio.h>
int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i)
        printf("%i ", a[i]);
    printf("\n");
    return 0;
}