#include <stdio.h>

int digitValue(int c, int b)
{
    int value;

    
    if (c >= '0' && c <= '9')
        value = c - '0';

    
    else if (c >= 'A' && c <= 'Z')
        value = c - 'A' + 10;

    
    else if (c >= 'a' && c <= 'z')
        value = c - 'a' + 10;

    
    else
        return -1;

    
    if (value < b)
        return value;
    else
        return -1;
}

int main()
{
    int ch;

    printf("Enter characters (Ctrl+C to stop):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == '\n') continue;  
        printf("'%c' -> %d\n", ch, digitValue(ch, 16));
    }

    return 0;
}

