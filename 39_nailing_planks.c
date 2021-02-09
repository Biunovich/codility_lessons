#include <stdio.h>
#include <stdlib.h>

inline static void
swap(int *a, int *b) {
    int t = *a;

    *a = *b;
    *b = t;
}

inline static void
heapify(int *C, int *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && C[largest] < C[l]) {
        largest = l;
    }

    if (r < n && C[largest] < C[r]) {
        largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        swap(&C[i], &C[largest]);
        heapify(C, arr, n, largest);
    }
}

inline static void
heap_sort(int *C, int *arr, int n) {
    int i;

    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(C, arr, n, i);
    }

    for (i = n - 1; i >= 0; i--) {
        swap(&arr[i], &arr[0]);
        swap(&C[i], &C[0]);
        heapify(C, arr, i, 0);
    }
}

inline static int
find_nail(int l, int r, int *C, int *arr, int M, int prev_result) {
    int max = M - 1;
    int min = 0;
    int result = -1;
    int mid;
    int i;

    while (min <= max) {
        mid = (min + max) / 2;

        if (C[mid] < l) {
            min = mid + 1;
            continue;
        }

        if (C[mid] > r) {
            max = mid - 1;
            continue;
        }

        result = arr[mid];
        break;
    }

    if (result == -1) {
        return -1;
    }

    for (i = mid - 1; (i >= 0) && (l <= C[i]); i--) {
        if (result > arr[i]) {
            result = arr[i];
            if (result <= prev_result) {
                return prev_result;
            }
        }
    }

    for (i = mid + 1; (i < M) && (r >= C[i]); i++) {
        if (result > arr[i]) {
            result = arr[i];
            if (result <= prev_result) {
                return prev_result;
            }
        }
    }

    if (result < prev_result) {
        return prev_result;
    }

    return result;
}

int solution(int A[], int B[], int N, int C[], int M) {
    int *arr = NULL;
    int i;
    int result = -1;

    arr = malloc(sizeof(int) * M);
    for (i = 0; i < M; i++) {
        arr[i] = i;
    }

    heap_sort(C, arr, M);

    for (i = 0; i < N; i++) {
        result = find_nail(A[i], B[i], C, arr, M, result);
        if (result == -1) {
            return -1;
        }
    }

    free(arr);
    
    return result + 1;
}

int main() {
    int A[] = { 1, 4, 5, 8 };
    int B[] = { 4, 5, 9, 10 };
    int C[] = { 4, 6, 7, 10, 2 };

    printf("Result: %d\n", solution(A, B, 4, C, 5));

    return 0;
}
