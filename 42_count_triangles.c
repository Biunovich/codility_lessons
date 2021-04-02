#include <stdio.h>

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

    if (l < N && A[largest] < A[l]) {
        largest = l;
    }

    if (r < N && A[largest] < A[r]) {
        largest = r;
    }

    if (i != largest) {
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
        swap(&A[0], &A[N - i - 1]);
        heapify(A, N - i - 1, 0);
    }
}

int solution(int A[], int N) {
    int t;
    int total = 0;

    if (N < 3) {
        return 0;
    }

    heap_sort(A, N);

    for (t = 2; t < N; t++) {
        int f = 0;
        int s = t - 1;

        while (f < s) {
            if (A[f] + A[s] > A[t]) {
                total += s - f;
                s--;
            } else {
                f++;
            }
        }
    }

    return total;
}

int main() {
    int A[] = { 10, 2, 5, 1, 8, 12 };

    printf("Result: %d\n", solution(A, 6));

    return 0;
}
