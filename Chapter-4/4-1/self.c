#include <stdio.h>

char TestSource[] = "53w5w35wfsafasffferfhjvjaofjapple adfasdf a";
char TestTarget[] = "apple";

int strrindex(char source[], char target[])
{
    int i, j, k;
    for (i = 0; source[i] != '\0'; i++)
    {
        for (j = i, k = 0; target[k] != '\0' && source[j] == target[k]; j++, k++)
            ;
        if (k > 0 && target[k] == '\0')
        {
            return i + k - 1;
        }
    }
    return -1;
}

int main()
{
    printf("%d", strrindex(TestSource, TestTarget));
    return 0;
}