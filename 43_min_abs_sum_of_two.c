#include <stdio.h>
#include <stdlib.h>

inline static int
min(int a, int b) {
    return a > b ? b : a;
}

inline static void
swap(int *a, int *b) {
    int temp = *a;

    *a = *b;
    *b = temp;
}

inline static void
heapify(int A[], int N, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < N && A[l] > A[largest]) {
        largest = l;
    }

    if (r < N && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&A[i], &A[largest]);
        heapify(A, N, largest);
    }
}

inline static void
heap_sort(int A[], int N) {
    int i;

    for (i = N / 2 - 1; i >= 0; i--) {
        heapify(A, N, i);
    }

    for (i = 0; i < N; i++) {
        swap(&A[0], &A[N - 1 - i]);
        heapify(A, N - 1 - i, 0);
    }
}

int solution(int A[], int N) {
    heap_sort(A, N);

    if ((A[0] >= 0 && A[N - 1] >= 0) || (A[0] <= 0 && A[N - 1] <= 0)) {
        return 2 * min(abs(A[0]), abs(A[N - 1]));
    }

    int l = 0;
    int r = N - 1;
    int minimum = abs(A[l] + A[r]);

    while (l <= r) {
        int curr = abs(A[l] + A[r]);
        minimum = min(curr, minimum);

        if (abs(A[l]) > abs(A[r])) {
            l++;
        } else {
            r--;
        }
    }

    return minimum;
}

int main() {
    int A[] = { -8, 4, 5, -10, 3 };

    printf("Result: %d\n", solution(A, 5));

    return 0;
}
