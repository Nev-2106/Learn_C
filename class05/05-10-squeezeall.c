#include <stdio.h>
int charIndex(char s[], int c)
{
    int i;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i] == c)
            return i;
    return -1;
}

void squeezeAll(char s[], char t[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (charIndex(t, s[i]) == -1)
            s[j++] = s[i];
    }
    s[j] = '\0';
}

int main()
{
    char s[]= "Hello world, how are you?";

    squeezeAll(s, "aeiou");
    printf("%s\n", s);
    squeezeAll(s, " ,");
    printf("%s\n", s);
    squeezeAll(s, "Hld");
    printf("%s\n", s);

    return 0;
}
