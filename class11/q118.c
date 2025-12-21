#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string {
    char *chars;
    int size;
};

struct string string_new(char *s) {
    struct string t;
    t.chars = strdup(s);
    t.size = strlen(s);
    return t;
}

struct string *string_println(struct string *s) {     //instead of recieving a full copy, recieve an address. 
    printf("%.*s\n", s->size, s->chars);  //used -> instead of .
    return s;
}

int main(int argc, char **argv)
{
    struct string s = string_new("hello");
    string_println(&s);
    return 0;
}
