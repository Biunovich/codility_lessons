#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N) {
    int i;
    int *peaks = NULL;
    int num_peaks = 0;
    int max_flags = 0;

    peaks = malloc(sizeof(int) * N);
    for (i = 1; i < N - 1; i++) {
        if (A[i - 1] < A[i] && A[i] > A[i + 1]) {
            peaks[num_peaks] = i;
            num_peaks++;
        }
    }

    if (num_peaks == 0 || num_peaks == 1 || num_peaks == 2) {
        free(peaks);
        return num_peaks;
    }

    for (i = 3; i <= num_peaks && i <= N / i + 1; i++) {
        int flags_left = i - 1;
        int pos = 1;
        int prev_pos = 0;

        while (flags_left > 0 && pos < num_peaks) {
            if (peaks[pos] - peaks[prev_pos] >= i) {
                flags_left--;
                prev_pos = pos;
                pos++;
            } else {
                pos++;
            }
        }

        if (max_flags < i - flags_left) {
            max_flags = i - flags_left;
        }
    }

    free(peaks);
    return max_flags;
}

int main() {
    int N = 12;
    int A[] = { 1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 };

    printf("Result: %d\n", solution(A, N));

    return 0;
}
