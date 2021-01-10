#include <stdio.h>
#include <stdlib.h>

inline static int 
max(int a, int b) {
    return a > b ? a : b;
}

int solution(int A[], int N) {
    int *diffs = NULL;
    int i;
    int current = 0;
    int total = 0;

    diffs = malloc(sizeof(int) * (N - 1));
    for (i = 0; i < N - 1; i++) {
        diffs[i] = A[i + 1] - A[i];
    }

    for (i = 0; i < N - 1; i++) {
        current = max(current + diffs[i], 0);
        total = max(current , total);
    }

    free(diffs);
    return total;
}

int main() {
    int A[] = { 23171, 21011, 21123, 21366, 21013, 21367 };

    printf("Result: %d\n", solution(A, 6));

    return 0;
}
