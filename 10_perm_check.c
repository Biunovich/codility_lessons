#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N) {
    int *B = NULL;
    int i;
    int count = 0;

    B = calloc(sizeof(int), N);
    if (B == NULL) {
        return -1;
    }

    for (i = 0; i < N; i++) {
        if (A[i] > N) {
            goto not_found;
        }

        if (B[A[i] - 1] == 0) {
            B[A[i] - 1] = 1;
            count++;
        }

        if (count == N) {
            free(B);
            B = NULL;
            return 1;
        }
    }

not_found:
    free(B);
    B = NULL;
    return 0;
}

int main() {
    int A[] = { 1, 2, 4, 3, 5 };

    printf("Result: %d\n", solution(A, 5));
    return 0;
}
