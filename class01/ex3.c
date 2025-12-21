#include <stdio.h>

int main(){
    int fahr, cel;
    int low=0, high=300, step=20;
    fahr=low;
    while (fahr<=high){
        cel = (fahr-32)*5/9;
        printf("%3d %3d\n",fahr,cel);
        fahr = fahr+step;
    }
}