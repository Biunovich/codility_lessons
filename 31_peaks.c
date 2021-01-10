#include <stdio.h>
#include <stdlib.h>

inline static int
check_peak(int peaks[], int l, int r) {
    int k;

    for (k = l; k <= r; k++) {
        if (peaks[k] == 1) {
            return 1;
        }
    }

    return 0;
}

inline static int
check_part(int peaks[], int i, int size) {
    int j;

    for (j = 1; j <= i; j++) {
        if (!check_peak(peaks, size * (j - 1), size * j)) {
            return 0;
        }
    }

    return 1;
}

int solution(int A[], int N) {
    int i;
    int *peaks = NULL;
    int max_parts = 0;

    peaks = calloc(sizeof(int), N);
    for (i = 1; i < N - 1; i++) {
        if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
            peaks[i] = 1;
        }
    }

    for (i = 1; i * i <= N; i++) {
        if (N % i != 0) {
            continue;
        }

        if (check_part(peaks, i, N / i)) {
            max_parts = max_parts > i ? max_parts : i;
        }

        if (check_part(peaks, N / i, i)) {
            max_parts = max_parts > N / i ? max_parts : N / i;
        }
    }

    free(peaks);
    return max_parts;
}

int main() {
    int N = 12;
    int A[] = { 1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 };

    printf("Result: %d\n", solution(A, N));

    return 0;
}
