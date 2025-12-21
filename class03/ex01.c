#include <stdio.h>
#include <math.h>

float power(float x,float y){
    float value;
    value = exp(y*log(x));
    return value;
}

int main(){
    float num=1;
    float y=0.5,p=0;
    for(num=1;num<=4;num = num+0.5){
        p = power(num,y);
        printf("%1.2f %3.2f\n",num,p);
    }


    return 0;
}