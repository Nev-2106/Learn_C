#include <stdio.h>

int main(){
    int num,i;
    for (num=' ', i=0; num<= '~'; num++, i++){
        printf("%4c %3d ", num, num);
        if((i+1)%8==0) printf("\n");
    }
    return 0;
}
