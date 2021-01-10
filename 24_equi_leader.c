#include <stdio.h>

int solution(int A[], int N) {
    int count = 0;
    int i;
    int value;
    int check = 0;
    int subcheck = 0;
    int total = 0;

    if (N == 1) {
        return 0;
    }

    for (i = 0; i < N; i++) {
        if (count == 0) {
            count++;
            value = A[i];
            continue;
        }

        if (value == A[i]) {
            count++;
        } else {
            count--;
        }
    }

    if (count == 0) {
        return 0;
    }

    for (i = 0; i < N; i++) {
        if (value == A[i]) {
            check++;
        }
    }

    if (check <= N / 2) {
        return 0;
    }

    for (i = 0; i < N; i++) {
        if (A[i] == value) {
            subcheck++;
        }

        if (subcheck > (i + 1) / 2) {
            if ((check - subcheck) > (N - i - 1) / 2) {
                total++;
            }
        }
    }

    return total;
}

int main() {
    int A[] = { 1, 2, 3, 4, 3, 5 };

    printf("Result: %d\n", solution(A, 6));

    return 0;
}
