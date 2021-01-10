#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N) {
    int i;
    int zeros = 0;
    int passed = 0;

    for (i = 0; i < N; i++) {
        if (A[i] == 0) {
            zeros++;
        }

        if (A[i] == 1) {
            passed += zeros;
            if (passed > 1000000000) {
                return -1;
            }
        }
    }

    return passed;
}

int main() {
    int A[] = { 0, 1, 0, 1, 1 };

    printf("Result: %d\n", solution(A, 5));
    return 0;
}
