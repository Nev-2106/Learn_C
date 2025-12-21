#include <stdio.h>

int main()
{
    int c, in_word = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            putchar(c);
            in_word = 1;
        } else if (in_word) {
            putchar(' ');
            in_word = 0;
        }
    }
    return 0;
}