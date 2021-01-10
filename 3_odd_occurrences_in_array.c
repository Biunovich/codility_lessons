#include <stdio.h>

static inline int
swap(int *l, int *r) {
    int t;

    t = *l;
    *l = *r;
    *r = t;
}

static inline int
partition(int A[], int l, int r) {
    int p = A[r];
    int i = l;
    int j;

    for (j = l; j < r; j++) {
        if (A[j] < p) {
            if (i != j) {
                swap(&A[i], &A[j]);
            }
            i++;
        }
    }

    swap(&A[i], &A[r]);
    return i;
}

static inline void
quicksort(int A[], int l, int r) {
    if (l < r) {
        int p = partition(A, l, r);
        quicksort(A, p + 1 , r);
        quicksort(A, l, p - 1);
    }
}

int solution1(int A[], int N) {
    int i;

    if (N == 1) {
        return A[0];
    }

    quicksort(A, 0, N - 1);
    for (i = 0; i < N; i++) {
        if (i + 1 == N) {
            return A[i];
        }

        if (A[i] == A[i + 1]) {
            i++;
        } else {
            return A[i];
        }
    }
}

int solution2(int A[], int N) {
    int res = A[0];
    int i;

    for (i = 1; i < N; i++) {
        res = res ^ A[i];
    }

    return res;
}

int main() {
    int A[] = { 1, 2, 3, 2, 1 };
    int i, j;

    printf("Result: %d\n", solution2(A, 5));
    return 0;
}
