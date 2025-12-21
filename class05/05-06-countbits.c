#include <stdio.h>

int countBits(unsigned int i)
{
    {
        int count = 0;
        while (i) {
            i &= i - 1;
            ++count;
        }
        return count;
    }
}

int main()
{
    for (int i = 0;  i <= 15;  ++i)
        printf("%d ", countBits(i));

    return 0;
}
