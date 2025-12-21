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

struct string *string_println(struct string *s) {
    printf("%.*s\n", s->size, s->chars);
    return s;
}

struct string *string_append(struct string *s, int c) {
    s->chars = realloc(s->chars, s->size + 1);    //increase memory using realloc
    s->chars[s->size] = c;//character put at the end
    s->size += 1;//size increased
    return s;
}

int main(int argc, char **argv)
{
    struct string s = string_new("hello");
    string_append(&s, '!');
    string_println(&s);
    return 0;
}
