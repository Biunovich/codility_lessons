#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Results {
  int *A;
  int M;
};

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result = { NULL, 0 };
    int **count_arr = NULL;
    int len;
    int i ,j;

    len = strlen(S);
    count_arr = malloc(sizeof(int *) * (len + 1));
    count_arr[0] = calloc(sizeof(int), 4);

    for (i = 1; i <= len; i++) {
        count_arr[i] = calloc(sizeof(int), 4);
        switch (S[i - 1])
        {
        case 'A':
            count_arr[i][0]++;
            break;
        case 'C':
            count_arr[i][1]++;
            break;
        case 'G':
            count_arr[i][2]++;
            break;
        case 'T':
            count_arr[i][3]++;
            break;
        }

        count_arr[i][0] += count_arr[i - 1][0];
        count_arr[i][1] += count_arr[i - 1][1];
        count_arr[i][2] += count_arr[i - 1][2];
        count_arr[i][3] += count_arr[i - 1][3];
    }

    result.A = malloc(sizeof(int) * M);
    result.M = M;

    for (i = 0; i < M; i++) {
        if (count_arr[Q[i] + 1][0] - count_arr[P[i]][0] > 0) {
            result.A[i] = 1;
        } else if (count_arr[Q[i] + 1][1] - count_arr[P[i]][1] > 0) {
            result.A[i] = 2;
        } else if (count_arr[Q[i] + 1][2] - count_arr[P[i]][2] > 0) {
            result.A[i] = 3;
        } else {
            result.A[i] = 4;
        }
    }
    
    return result;
}

int main() {
    int P[] = { 2, 5, 0 };
    int Q[] = { 4, 5, 6 };
    struct Results result = { NULL, 0 };
    int i;

    result = solution("CAGCCTA", P, Q, 3);
    printf("Result len: %d array:\n", result.M);
    for (i = 0; i < 3; i++) {
        printf("%d ", result.A[i]);
    }

    printf("\n");
    free(result.A);
    result.A = NULL;
    return 0;
}
