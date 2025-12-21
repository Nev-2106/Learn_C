#include <stdio.h>

int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int count = 0;
    for (int i = 2; i <= 100000; i++) {
        if (isPrime(i)) {
            count ++;
        }
    }
    printf("Number of Prime Numbers: %d\n",count);
    return 0;
}