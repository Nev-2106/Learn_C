#include <stdio.h>

int main(){
    float fahr,cel,low=0,high=100,step=10;
    cel = low;
    while(cel<=high){
        fahr = 32+(cel*9/5);
        printf("%5.1f %5.1f\n",cel,fahr);
        cel = cel+step;
    }

}