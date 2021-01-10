#include <stdio.h>
#include <stdlib.h>

struct Results {
  int *A;
  int N;
};

struct Results solution(int A[], int N, int K) {
    struct Results result = { NULL, 0 };
    int i;

    if (N == 0) {
        return result;
    }

    int k = K % N;
    result.A = malloc(sizeof(int) * N);
    if (result.A == NULL) {
        return result;
    }

    result.N = N;
    for (int i = 0; i < N; i++) {
        result.A[(i + k) % N] = A[i];
    }

    return result;
}

int main() {
    int A[] = { 1, 2, 3, 4, 5 };
    struct Results result = { NULL, 0 };
    int i;

    result = solution(A, 5, 3);
    printf("Result: ");
    for (i = 0; i < result.N; i++) {
        printf("%d ", result.A[i]);
    }
    printf("\n");

    free(result.A);
    result.A = NULL;
    return 0;
}
