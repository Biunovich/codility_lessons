#include <stdio.h>

int solution(int A[], int N) {
    unsigned long sum = 0;
    unsigned long n = N;
    unsigned long full_sum;
    int i;

    full_sum = ((n * n) + 3 * n + 3) / 2;
    for (i = 0; i < N; i++) {
        sum += A[i];
    }

    return (int)(full_sum - sum);
}

int main() {
    int A[] = { 1, 2, 3, 4, 5 };

    printf("Result: %d\n", solution(A, 5));

    return 0;
}
