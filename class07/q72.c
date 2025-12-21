	#include <stdio.h>
#include <ctype.h>

double number;

int getop(void)
{
    int c;

    // skip blanks
    while (isblank(c = getchar()))
        ;

    if (c == EOF) return -1;
    if (c == '\n') return 0;
    if (!isdigit(c)) return c;

    // read digits into a number
    double val = 0;
    do {
        val = val * 10 + (c - '0');
        c = getchar();
    } while (isdigit(c));

    number = val;
    return '0';
}

int main()
{
    for (;;) {
        int c = getop();
        switch (c) {
            case -1: printf("EOF\n"); return 0;
            case 0:  printf("newline\n"); break;
            case '0': printf("%g\n", number); break;
            default: printf("unknown operator '%c'\n", c); break;
        }
    }
    return 0;
}
