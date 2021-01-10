#include <stdio.h>
#include <stdlib.h>

inline static int 
max(int a, int b) {
    return a > b ? a : b;
}

int solution(int A[], int N) {
    int i;
    int current;
    int total;

    current = A[0];
    total = A[0];
    for (i = 1; i < N; i++) {
        current = max(current + A[i], A[i]);
        total = max(current, total);
    }

    return total;
}

int main() {
    int A[] = { 23171, 21011, 21123, 21366, 21013, 21367 };

    printf("Result: %d\n", solution(A, 6));

    return 0;
}
