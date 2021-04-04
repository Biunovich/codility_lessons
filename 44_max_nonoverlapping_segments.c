#include <stdio.h>

int solution(int A[], int B[], int N) {
    if (N <= 1) {
        return N;
    }

    int i;
    int segments = 1;
    int last = 0;

    for (i = 1; i < N; i++) {
        if (A[i] <= B[last]) {
            continue;
        }

        segments++;
        last = i;
    }

    return segments;
}

int main() {
    int A[] = { 1, 3, 7, 9, 9 };
    int B[] = { 5, 6, 8, 9, 10 };

    printf("Result: %d\n", solution(A, B, 5));

    return 0;
}
