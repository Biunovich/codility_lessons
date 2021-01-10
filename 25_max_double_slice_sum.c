#include <stdio.h>
#include <stdlib.h>

inline static int 
max(int a, int b) {
    return a > b ? a : b;
}

inline static int 
max_slice(int A[], int start, int stop) {
    int current_max = 0;
    int total_max = 0;
    int i;

    for (i = start; i < stop; i++) {
        current_max = max(0, current_max + A[i]);
        total_max = max(total_max, current_max);
    }

    return total_max;
}

int solution(int A[], int N) {
    int i;
    int *l_arr = NULL;
    int *r_arr = NULL;
    int max_val = 0;

    l_arr = calloc(sizeof(int), N);
    r_arr = calloc(sizeof(int), N);

    for (i = 1; i < N - 1; i++) {
        l_arr[i] = max(l_arr[i - 1] + A[i], 0);
    }

    for (i = N - 2; i > 0; i--) {
        r_arr[i] = max(r_arr[i + 1] + A[i], 0);
    }

    for (i = 1; i < N - 1; i++) {
        max_val = max(max_val, l_arr[i - 1] + r_arr[i + 1]);
    }

    free(r_arr);
    free(l_arr);
    return max_val;
}

int main() {
    int A[] = { 3, 2, 6, -1, 4, 5, -1, 2};

    printf("Result: %d\n", solution(A, 8));

    return 0;
}
