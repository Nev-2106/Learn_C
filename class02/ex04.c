#include <stdio.h>

#define SPACE 32
#define TILDE 126
#define STEP 1

int main(){
    int num;
    for (num = SPACE; num <= TILDE; num = num + STEP){
        printf("%5c %5d\n ", num, num);
    }
    return 0;
}
