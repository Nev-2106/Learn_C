#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int value = 10;   // default

    if (argc == 1) {
        // print default 10
    }
    else if (argc == 2) {
        if (argv[1][0] != '-') {
            printf("illegal argument\n");
            return 0;
        }
        value = atoi(argv[1] + 1);  // skip '-'
    }
    else {
        printf("too many arguments\n");
        return 0;
    }

    printf("%d\n", value);
    return 0;
}

