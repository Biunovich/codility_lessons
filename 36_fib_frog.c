#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

inline static int
min(int a, int b) {
    return a > b ? b : a;
}

int solution(int A[], int N) {
    int i, j;
    int *fibs = NULL;
    int *res = NULL;
    int result;

    if (N == 0 || N == 1) {
        return 1;
    }

    fibs = malloc(sizeof(int) * N);
    res = malloc(sizeof(int) * (N + 1));

    fibs[0] = 1;
    fibs[1] = 2;
    for (i = 2; fibs[i - 1] <= N + 1; i++) {
        fibs[i] = fibs[i - 2] + fibs[i - 1];
        if (N + 1 == fibs[i]) {
            free(fibs);
            free(res);
            return 1;
        }
    }

    for (i = 0; i < N + 1; i++) {
        res[i] = INT_MAX;
    }

    for (i = 0; i < N + 1; i++) {
        if ((i < N && A[i]) || i == N) {
            for (j = 0; fibs[j] <= i + 1; j++) {
                if (i + 1 == fibs[j]) {
                    res[i] = 1;
                    break;
                }

                res[i] = min(res[i] - 1, res[i - fibs[j]]) + 1;
            }
        }
    }

    free(fibs);
    result = res[N];
    free(res);
    return result == INT_MAX ? -1 : result;
}

int main() {
    int N = 11;
    int A[] = { 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0 };

    printf("Result: %d\n", solution(A, N));

    return 0;
}
