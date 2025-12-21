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
    s->chars = realloc(s->chars, s->size + 1);
    s->chars[s->size] = c;
    s->size += 1;
    return s;
}

struct string *string_extend(struct string *s, struct string *t) {
    s->chars = realloc(s->chars, s->size + t->size);
    memcpy(s->chars + s->size, t->chars, t->size);       //grow memory by t->size, copy over t->chars, increase s->size
    s->size += t->size;
    return s;
}

int main(int argc, char **argv)
{
    struct string s = string_new("hello");
    struct string t = string_new("world");

    string_append(&s, ' ');
    string_extend(&s, &t);

    string_println(&s);
    return 0;
}
