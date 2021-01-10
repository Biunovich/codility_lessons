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
    l = i * 2 + 1;
    r = i * 2 + 2;

    if (l < N && A[largest] < A[l]) {
        largest = l;
    }

    if (r < N && A[largest] < A[r]) {
        largest = r;
    }

    if (i != largest) {
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
    int i;
    long sum;

    heap_sort(A, N);
    for (i = 0; i < N - 2; i++) {
        sum = (long)A[i] + (long)A[i + 1];
        if (sum > A[i + 2]) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int A[] = { 10, 2, 5, 1, 8, 20 };

    printf("Result: %d\n", solution(A, 6));
    return 0;
}
