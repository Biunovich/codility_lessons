#include <stdio.h>

inline static int
divisable(int size, int k, int A[], int N) {
    int i;
    int curr_sum = 0;

    for (i = 0; i < N; i++) {
        curr_sum += A[i];
        if (curr_sum > size) {
            curr_sum = A[i];
            k--;
        }

        if (k == 0) {
            return -1;
        }
    }

    return 1;
}

int solution(int K, int M, int A[], int N) {
    int i;
    int max = 0;
    int current;
    int min = 0;

    for (i = 0; i < N; i++) {
        max += A[i];
        min = min < A[i] ? A[i] : min;
    }

    while (min < max) {
        current = (min + max) / 2;
        if (divisable(current, K, A, N) == 1) {
            if (max == current) {
                max = current;
                break;
            }

            max = current;
            continue;
        }

        if (min == current) {
            break;
        }

        min = current;
    }

    return max;
}

int main() {
    int A[] = { 4, 4 };

    printf("Result: %d\n", solution(2, 4, A, 2));

    return 0;
}
