#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define struct string here */

int main(int argc, char **argv)
{
    struct string s = { strdup("hello"), 5 };
    printf("\"%.*s\"\n", s.size, s.chars);
    return 0;
}
