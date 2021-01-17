#include <stdio.h>
#include <stdlib.h>

struct Results {
    int *A;
    int M;
};

struct Results solution(int N, int P[], int Q[], int M) {
    int i, j;
    struct Results res = { NULL, 0 };
    int *erato = NULL;
    int *semiprimes = NULL;

    res.A = calloc(sizeof(int), M);
    res.M = M;
    erato = calloc(sizeof(int), N / 2 + 1);
    semiprimes = calloc(sizeof(int), N + 1);

    for (i = 2; i * i <= N / 2; i++) {
        if (erato[i] == 0) {
            for (j = i * i; j <= N / 2; j += i) {
                erato[j] = 1;
            }
        }
    }

    for (i = 2; i <= N / 2; i++) {
        if (erato[i] == 0) {
            for (j = i; j <= N / 2; j++) {
                if (erato[j] == 0) {
                    if (i * j <= N) {
                        semiprimes[i * j] = 1;
                    }
                }
            }
        }
    }

    for (i = 4; i <= N; i++) {
        semiprimes[i] += semiprimes[i - 1];
    }

    for (i = 0; i < M; i++) {
        res.A[i] = semiprimes[Q[i]] - semiprimes[P[i] - 1];
    }

    free(semiprimes);
    free(erato);
    return res;
}

int main() {
    int i;
    int P[] = { 1, 4, 16 };
    int Q[] = { 26, 10, 20 };
    struct Results res = { NULL, 0 };

    res = solution(26, P, Q, 3);
    printf("Result: ");
    for (i = 0; i < res.M; i++) {
        printf("%d ", res.A[i]);
    }
    printf("\n");

    return 0;
}
