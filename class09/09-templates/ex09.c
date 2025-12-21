#include <stdio.h>
#include <ctype.h>

void swapchars(char *c, char *d)
{
    char temp = *c;
    *c = *d;
    *d = temp;
}

char *revchars(char *s, char *t)
{
    char *start = s;
    while (s < t) {
        t--;
        swapchars(s, t);
        s++;
    }
    return start;
}

char *revwords(char *s)
{
    char *end = s;
    while (*end != '\0') {
        end++;
    }

    char *word_start = s;
    char *word_end = s;

    while (*word_end != '\0') {
        if (*word_end == ' ') {
            revchars(word_start, word_end);
            word_end++;
            word_start = word_end;
        } else {
            word_end++;
        }
    }
    revchars(word_start, word_end);

    return s;
}

int main()
{
    char s[100] = "retep repip dekcip a kcep fo delkcip reppep";
    printf("%s\n", revwords(s));
    return 0;
}
