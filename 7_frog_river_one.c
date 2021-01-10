#include <stdio.h>
#include <stdlib.h>

int solution(int X, int A[], int N) {
    int *B = NULL;
    int i;
    int count = 0;

    B = calloc(sizeof(int), X);
    if (B == NULL) {
        return -2;
    }

    for (i = 0; i < N; i++) {
        if (B[A[i]] == 0) {
            B[A[i]] = 1;
            count++;
            if (count == X) {
                free(B);
                B = NULL;
                return i;
            }
        }
    }

    free(B);
    B = NULL;
    return -1;
}

int main() {
    int A[] = { 1, 2, 3, 4, 3, 5 };

    printf("Result: %d\n", solution(5, A, 6));

    return 0;
}
