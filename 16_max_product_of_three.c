#include <stdio.h>
#include <stdlib.h>

inline static void
swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

inline static void
heapify(int A[], int N, int i) {
    int r;
    int l;
    int largest;

    largest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;

    if ((l < N) && (A[l] > A[largest])) {
        largest = l;
    }

    if ((r < N) && (A[r] > A[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(&A[largest], &A[i]);
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
    int max;

    heap_sort(A, N);
    max = A[N - 1] * A[N - 2] * A[N - 3];
    if (max < A[N - 1] * A[0] * A[1]) {
        max = A[N - 1] * A[0] * A[1];
    }

    return max;
}

int main() {
    int A[] = { 3, 1, 5, 2, 8 };

    printf("Result: %d\n", solution(A, 5));
    return 0;
}
