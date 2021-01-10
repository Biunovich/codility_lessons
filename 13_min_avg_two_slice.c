#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N) {
    int i;
    float min;
    float current_sum;
    int index;

    current_sum = A[0] + A[1];
    min = current_sum / 2;
    index = 0;
    for (i = 2; i < N; i++) {
        current_sum += A[i];
        if (current_sum / 3 < min) {
            min = current_sum / 3;
            index = i - 2;
        }

        current_sum -= A[i - 2];
        if (current_sum / 2 < min) {
            min = current_sum / 2;
            index = i - 1;
        }
    }

    return index;
}

int main() {
    int A[] = { 4, 2, 2, 5, 1, 5, 8 };

    printf("Result: %d\n", solution(A, 7));
    return 0;
}
