#include <stdio.h>

inline static int
find_max(int dp[]) {
    int i;
    int max = dp[0];

    for (i = 1; i < 6; i++) {
        if (dp[i] > max) {
            max = dp[i];
        }
    }

    return max;
}

int solution(int A[], int N) {
    int dp[6] = { A[0], A[0], A[0], A[0], A[0], A[0] };
    int i;

    for (i = 1; i < N; i++) {
        dp[i % 6] = find_max(dp) + A[i];
    }

    return dp[(i - 1) % 6];
}

int main() {
    int A[] = { 1, -2, 0, 9, -1, -2 };

    printf("Result: %d\n", solution(A, 6));

    return 0;
}