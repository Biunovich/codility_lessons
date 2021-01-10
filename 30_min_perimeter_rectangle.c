#include <stdio.h>

int solution(int N) {
    int i = 1;
    int max_div = 1;

    while (i * i <= N) {
        if (N % i == 0) {
            max_div = i;
        }

        i++;
    }

    int j = N / max_div;

    return 2 * (max_div + j);
}

int main() {
    int N = 48;

    printf("Result: %d\n", solution(N));

    return 0;
}
