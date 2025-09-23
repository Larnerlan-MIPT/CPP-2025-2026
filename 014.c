#include <stdio.h>
#include <stdlib.h>

void encrypt(char* a, int b)
{
    int c = 0;
    
    while (a[c] != '\0')
    {
        if (a[c] >= 'A' && a[c] <= 'Z')
        {
            a[c] = 'A' + (a[c] - 'A' + b) % 26;
        }
        else if (a[c] >= 'a' && a[c] <= 'z')
        {
            a[c] = 'a' + (a[c] - 'a' + b) % 26;
        }
        c++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
        return 1;

    char *d = argv[1];
    char *e = argv[2];
    int f = atoi(argv[3]);
    
    FILE *g = fopen(d, "r");
    FILE *h = fopen(e, "w");
    
    char i[1000];
    
    while (fgets(i, 1000, g) != NULL)
    {
        encrypt(i, f);
        fprintf(h, "%s", i);
    }
    
    fclose(g);
    fclose(h);
    
    return 0;
}