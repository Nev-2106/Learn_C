#include <stdio.h>

int main(){
    float fahr, cel;
    float low=0, high=300, step=20;
    fahr=low;
    while (fahr<=high){
        cel = (fahr-32)*5/9;
        printf("%5.1f %5.1f\n",fahr,cel);
        fahr = fahr+step;
    }
}