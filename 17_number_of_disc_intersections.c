#include <stdio.h>
#include <stdlib.h>

inline static void
swap(long *a, long *b) {
    long temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

inline static void
heapify(long A[], int N, int i) {
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
heap_sort(long A[], int N) {
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
    long *starts = NULL;
    long *ends = NULL;
    int res = 0;;
    int i;
    int j = 0;
    int current_circles = 0;

    starts = malloc(sizeof(long) * N);
    if (starts == NULL) {
        return -1;
    }

    ends = malloc(sizeof(long) * N);
    if (ends == NULL) {
        free(starts);
        return -1;
    }

    for (i = 0; i < N; i++) {
        starts[i] = (long)i - (long)A[i];
        ends[i] = (long)i + (long)A[i];
    }

    heap_sort(starts, N);
    heap_sort(ends, N);
    for (i = 0; i < N; i++) {
        if (starts[i] <= ends[j]) {
            res += current_circles;
            current_circles++;
        } else {
            while (starts[i] > ends[j]) {
                current_circles--;
                j++;
            }

            res += current_circles;
            current_circles++;
        }

        if (res > 10000000) {
            res = -1;
            goto exit;
        }
    }

exit:
    free(starts);
    free(ends);
    return res;
}

int main() {
    int A[] = { 1, 5, 2, 1, 4, 0};

    printf("Result: %d\n", solution(A, 6));
    return 0;
}
