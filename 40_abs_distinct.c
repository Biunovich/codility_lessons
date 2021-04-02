#include <stdio.h>
#include <stdlib.h>

inline static long
max(long a, long b) {
    return a > b ? a : b;
}

int solution(int A[], int N) {
    int distinct = 1;
    long long start = 0;
    long long end = N - 1;
    long long curr_max = max(labs(A[start]), labs(A[end]));

    while (start <= end) {
        if (labs(A[start]) == curr_max) {
            start++;
            continue;
        }

        if (labs(A[end]) == curr_max) {
            end--;
            continue;
        }

        curr_max = max(labs(A[start]), labs(A[end]));
        distinct++;
    }

    return distinct;
}

int main() {
    int A[] = { -2147483648, -1, 0, 1 };

    printf("Result: %d\n", solution(A, 4));

    return 0;
}
