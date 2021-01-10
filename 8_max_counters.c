#include <stdio.h>
#include <stdlib.h>

struct Results {
  int *C;
  int L;
};

struct Results solution(int N, int A[], int M) {
    struct Results result = { NULL, 0 };
    int i;
    int max = 0;
    int curmax = 0;

    result.C = calloc(sizeof(int), N);
    if (result.C == NULL) {
        return result;
    }

    result.L = N;
    for (i = 0; i < M; i++) {
        if (A[i] == N + 1) {
            max = curmax;
        } else {
            if (result.C[A[i] - 1] < max) {
                result.C[A[i] - 1] = max + 1;
            } else {
                result.C[A[i] - 1]++;
            }

            if (result.C[A[i] - 1] > curmax) {
                curmax = result.C[A[i] - 1];
            }
        }
    }

    for (i = 0; i < N; i++) {
        if (result.C[i] < max) {
            result.C[i] = max;
        }
    }

    return result;
}

int main() {
    int A[] = { 1, 2, 3, 4, 3, 5 };
    struct Results result = { NULL, 0 };
    int i;

    result = solution(5, A, 6);
    printf("Result len: %d array:\n", result.L);
    for (i = 0; i < 5; i++) {
        printf("%d ", result.C[i]);
    }

    printf("\n");
    free(result.C);
    result.C = NULL;
    return 0;
}
