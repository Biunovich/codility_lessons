#include <stdio.h>
#include <stdlib.h>

int solution(int M, int A[], int N) {
    char *visited = calloc(sizeof(char), M);
    int left = 0;
    int right = 0;
    int slices = 0;

    while (left < N && right < N) {
        if (visited[A[right]]) {
            visited[A[left]] = 0;
            left++;
        } else {
            visited[A[right]] = 1;
            slices += right - left + 1;
            right++;

            if (slices >= 1000000000) {
                slices = 1000000000;
                break;
            }
        }
    }

    free(visited);
    visited = NULL;
    return slices;
}

int main() {
    int A[] = { 3, 4, 5, 5, 2 };

    printf("Result: %d\n", solution(6, A, 5));

    return 0;
}
