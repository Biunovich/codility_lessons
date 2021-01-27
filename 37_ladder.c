#include <stdio.h>
#include <stdlib.h>

struct Results {
  int *C;
  int L;
};

struct Results solution(int A[], int B[], int L) {
    struct Results result = { NULL, 0 };
    int i;
    int max = 0;
    unsigned long *steps = NULL;

    result.C = malloc(sizeof(int) * L);
    result.L = L;

    for (i = 0; i < L; i++) {
        max = max < A[i] ? A[i] : max;
    }

    steps = malloc(sizeof(unsigned long) * max);
    steps[0] = 1;
    steps[1] = 2;

    for (i = 2; i < max; i++) {
        steps[i] = steps[i - 2] + steps[i - 1];
    }

    for (i = 0; i < L; i++) {
        result.C[i] = steps[A[i] - 1] % (1 << B[i]);
    }

    free(steps);
    return result;
}

int main() {
    int i;
    int A[] = { 4, 4, 5, 5, 1 };
    int B[] = { 3, 2, 4, 3, 1 };
    struct Results res = { NULL, 0 };

    res = solution(A, B, 5);

    for (i = 0; i < res.L; i++) {
        printf("%d ", res.C[i]);
    }

    printf("\n");
    free(res.C);
    return 0;
}
