#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: ./line_extractor <input_file> <output_file> <lines>\n");
        return 1;
    }

    char *a = argv[1];
    char *b = argv[2];
    char *c = argv[3];
    
    FILE *d = fopen(a, "r");
    if (d == NULL)
    {
        printf("Error: File %s does not exist!\n", a);
        return 1;
    }
    
    FILE *e = fopen(b, "w");
    
    int f = 0;
    int g = 0;
    char *h = strchr(c, ':');
    
    if (h != NULL)
    {
        *h = '\0';
        f = atoi(c);
        g = atoi(h + 1);
        
        if (g <= f)
        {
            printf("Error: Wrong lines format!\n");
            return 1;
        }
    }
    else
    {
        f = atoi(c);
        g = f + 1;
    }
    
    char i[1000];
    int j = 1;
    
    while (fgets(i, 1000, d) != NULL)
    {
        if (j >= f && j < g)
        {
            fprintf(e, "%s", i);
        }
        j++;
    }
    
    fclose(d);
    fclose(e);
    
    return 0;
}