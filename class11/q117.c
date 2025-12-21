#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
    char *chars;
    int size;
};

struct string string_new(char *s) {
    struct string t;
    t.chars = strdup(s);     //strdup alloctes memory and copies the string.i own the memory
    t.size = strlen(s);        //size only stores characters, not terminating \0
    return t;
}

struct string string_println(struct string s) {
    printf("%.*s\n", s.size, s.chars);     //%.s for printing exactly size chars
    return s;
}

int main(int argc, char **argv)
{
    struct string s = string_new("hello");
    string_println(s);
    return 0;
}
