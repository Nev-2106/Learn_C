#include <stdio.h>

int charIndex(char s[], int c)
{
    int i;
    int j = -1;
    for (i = 0; s[i] !='\0' ; ++i) {
        if (s[i] == c)
            return i;
        if (s[i] == '\0')
            return j;
    }
    return -1;
}

int main()
{
    char s[]= "Hello world, how are you?";

    printf("%d\n", charIndex(s, 'H'));
    printf("%d\n", charIndex(s, 'w'));
    printf("%d\n", charIndex(s, '?'));
    printf("%d\n", charIndex(s, 'q'));
    printf("%d\n", charIndex(s, '\0'));

    return 0;
}
