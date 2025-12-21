#include <stdio.h>

int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    return c;
}

void toLower(char s[])
{

    for (int i = 0; s[i] != '\0'; ++i)
        s[i] = (char)lower((unsigned char)s[i]);
    
}

int main()
{
    char s[] = "Hello World How Are You?";
    toLower(s);
    printf("%s\n", s);
    return 0;
}
