#include <stdio.h>
#include <stdlib.h>

int solution(int A, int B, int K) {
    int l;
    int r;

    l = A / K;
    if (A % K == 0) {
        l--;
    }
    r = B/ K;

    return r - l;
}

int main() {
    printf("Result: %d\n", solution(6, 2, 11));
    return 0;
}
