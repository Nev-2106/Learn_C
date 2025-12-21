#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int value = 10;      // default

    if (argc == 1) {
        // keep default 10
    }
    else if (argc == 2) {
        value = atoi(argv[1]);
    }
    else {
        printf("too many arguments\n");
        return 0;
    }

    printf("%d\n", value);
    return 0;
}
