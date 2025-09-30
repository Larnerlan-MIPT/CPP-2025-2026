#include <stdio.h>
#include <string.h>

void used_chars(const char* str, char* used)
{
    int letters[26] = {0};
    
    while (*str != '\0')
    {
        if (*str >= 'A' && *str <= 'Z')
            letters[*str - 'A'] = 1;
        else if (*str >= 'a' && *str <= 'z')
            letters[*str - 'a'] = 1;
        str++;
    }
    
    int pos = 0;
    for (int i = 0; i < 26; i++)
    {
        if (letters[i] == 1)
        {
            used[pos] = 'a' + i;
            pos++;
        }
    }
    used[pos] = '\0';
}

int main()
{
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);
    strcpy(s, "123!\%0");
    used_chars(s, u);
    printf("%s\n", u);
    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);
}