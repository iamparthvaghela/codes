#include <stdio.h>
#include <math.h>
#include <string.h>

void rabinkarp(char *string, char *pattern);

int main()
{
    char string[100], pattern[100];
    printf("Enter String: ");
    scanf("%s", string);
    printf("Enter Pattern: ");
    scanf("%s", pattern);
    rabinkarp(string, pattern);
}

void rabinkarp(char *string, char *pattern)
{
    int string_len = strlen(string);
    int pattern_len = strlen(pattern);
    int base = 26;
    int hash = 0;
    int hash_compare = 0;
    int k = pattern_len;
    int flag = 0;

    if (string_len < pattern_len)
    {
        printf("Pattern Not Found\n");
        return;
    }

    for (int i = 0; i < pattern_len; i++)
    {
        hash += (pattern[i] * pow(base, k));
        k--;
    }

    for (int i = 0; i < string_len - pattern_len + 1; i++)
    {
        k = pattern_len;
        hash_compare = 0;
        for (int j = i; j < i + pattern_len; j++)
        {
            int ascii = (int)string[j];
            hash_compare += (ascii * pow(base, k));
            k--;
        }

        if (hash == hash_compare)
        {
            printf("Pattern found at %d\n", i + 1);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Pattern Not Found\n");
    }
}
