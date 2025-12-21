#include <stdio.h>
int main()
{
    int c;
    int d[10];
    d[0] = d[1] = d[2] = d[3] = d[4] = d[5] = d[6] = d[7] = d[8] = d[9] = 0;
    while ((c = getchar()) != EOF) {
        if (c == '0') ++d[0];
        if (c == '1') ++d[1];
        if (c == '2') ++d[2];
        if (c == '3') ++d[3];
        if (c == '4') ++d[4];
        if (c == '5') ++d[5];
        if (c == '6') ++d[6];
        if (c == '7') ++d[7];
        if (c == '8') ++d[8];
        if (c == '9') ++d[9];
    }
    printf("0 %d\n", d[0]);
    printf("1 %d\n", d[1]);
    printf("2 %d\n", d[2]);
    printf("3 %d\n", d[3]);
    printf("4 %d\n", d[4]);
    printf("5 %d\n", d[5]);
    printf("6 %d\n", d[6]);
    printf("7 %d\n", d[7]);
    printf("8 %d\n", d[8]);
    printf("9 %d\n", d[9]);
    return 0;
}
