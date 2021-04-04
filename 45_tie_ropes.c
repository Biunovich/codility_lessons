#include <stdio.h>

int solution(int K, int A[], int N) {
    int i;
    int curr = 0;
    int ropes = 0;

    for (i = 0; i < N; i++) {
        curr += A[i];

        if (curr >= K) {
            ropes++;
            curr = 0;
        }
    }

    return ropes;
}

int main() {
    int A[] = { 1, 2, 3, 4, 1, 1, 3 };

    printf("Result: %d\n", solution(4, A, 7));

    return 0;
}
