#include <stdio.h>

int main(int argc, char **argv)
{
    argv++;  // skip program name

    while (*argv) {
        printf("%s", *argv);
        argv++;
        if (*argv) printf(" ");
    }
    printf("\n");
    return 0;
}

