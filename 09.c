#include <stdio.h>

void trim_after_first_space(char a[])
{
    int b = 0;
    while (a[b] != '\0')
    {
        if (a[b] == ' ')
        {
            a[b] = '\0';
            break;
        }
        b++;
    }
}

int main()
{
    char a[] = "Cats and Dogs";
    printf("%s\n", a);
    trim_after_first_space(a);
    printf("%s\n", a);
    
    return 0;
}