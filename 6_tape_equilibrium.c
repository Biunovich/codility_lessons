#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N) {
    int *B = NULL;
    int i;
    int min;

    if (N == 2) {
        return abs(A[0] - A[1]);
    }

    B = malloc(sizeof(int) * N);
    if (B == NULL) {
        return -1;
    }

    B[0] = A[0];
    for (i = 1; i < N; i++) {
        B[i] = B[i - 1] + A[i];
    }

    min = abs(B[0] - B[N - 1] + B[0]);
    for (i = 1; i < N - 1; i++) {
        int diff = abs(B[i] - B[N - 1] + B[i]);
        if (diff < min) {
            min = diff;
        }
    }

    free(B);
    B = NULL;
    return min;
}

int main() {
    int A[] = { 1, 2, 3, 2, 1 };

    printf("Result: %d\n", solution(A, 5));

    return 0;
}
