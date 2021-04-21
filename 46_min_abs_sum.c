#include <stdio.h>
#include <stdlib.h>

inline static int
min(int a, int b) {
    return a > b ? b : a;
}

int solution(int A[], int N) {
    int i, j;
    int sum = 0;
    int max = 100;

    int *counts = calloc(sizeof(int), max + 1);
    for (i = 0; i < N; i++) {
        sum += abs(A[i]);
        counts[abs(A[i])]++;
    }

    int *possible = malloc(sizeof(int) * (sum + 1));
    for (i = 0; i <= sum; i++) {
        possible[i] = -1;
    }

    possible[0] = 0;

    for (i = 0; i <= max; i++) {
        if (counts[i] > 0) {
            for (j = 0; j <= sum; j++) {
                if (possible[j] >= 0) {
                    possible[j] = counts[i];
                } else if (j - i >= 0 && possible[j - i] > 0) {
                    possible[j] = possible[j - i] - 1;
                }
            }
        }
    }

    int result = sum;
    for (i = 0; i <= sum / 2; i++) {
        if (possible[i] >= 0) {
            result = min(result, sum - 2 * i);
        }
    }

    free(counts);
    free(possible);
    return result;
}

int main() {
    int A[] = { 1, 5, 2, -2 };

    printf("Result: %d\n", solution(A, 4));

    return 0;
}