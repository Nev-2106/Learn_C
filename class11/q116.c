#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
    char *chars;  //pointer to actual characters in memory
    int size;  //number of characters
};

int main(int argc, char **argv)  //backbone program for 7-10
{
    struct string s = { strdup("hello"), 5 };
    printf("\"%.*s\"\n", s.size, s.chars);
    return 0;
}
