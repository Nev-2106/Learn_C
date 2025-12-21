#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc > 1) {//check if any commandline besides program name
        int value = atoi(argv[1]); //if ==1, only program name was given, skip printing
        printf("%d\n", value);
    }
    return 0;
}
