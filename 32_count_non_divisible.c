#include <stdio.h>
#include <stdlib.h>

struct Results {
  int *C;
  int L;
};

struct Results solution(int A[], int N) {
    int i, j;
    struct Results res = { NULL, 0 };
    int *is_exists = NULL;

    res.C = calloc(sizeof(int), N);
    res.L = N;
    is_exists = calloc(sizeof(int), N * 2);

    for (i = 0; i < N; i++) {
        is_exists[A[i]]++;
    }

    for (i = 0; i < N; i++) {
        int div = N;

        for (j = 1; j * j <= A[i]; j++) {
            if (A[i] % j == 0) {
                if (is_exists[j]) {
                    div -= is_exists[j];
                }

                if (is_exists[A[i] / j] && j != A[i] / j) {
                    div -= is_exists[A[i] / j];
                }
            }
        }

        res.C[i] = div;
    }

    free(is_exists);
    return res;
}

int main() {
    int i;
    int N = 5;
    int A[] = { 3, 1, 2, 3, 6 };
    struct Results res = { NULL, 0 };

    res = solution(A, N);
    printf("Result: ");
    for (i = 0; i < res.L; i++) {
        printf("%d ", res.C[i]);
    }
    printf("\n");

    return 0;
}
