#include <stdio.h>

char *monthName(int n)
{
    // FIX: second dimension must be 4 (3 chars + '\0')
    static char name[][4] = {
        "???", // illegal month
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    return (1 <= n && n <= 12) ? name[n] : name[0];
}

int main(void)
{
    printf("%s\n", monthName(7));
    return 0;
}

