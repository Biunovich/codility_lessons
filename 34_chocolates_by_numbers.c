#include <stdio.h>

int gcd(int a, int b) {
    int mod = a % b;

    if (mod == 0) {
        return b;
    }

    return gcd(b, mod);
}

int solution(int N, int M) {
    return N / gcd(N, M);
}

int main() {
    int N = 10;
    int M = 4;

    printf("Result: %d\n", solution(N, M));

    return 0;
}
