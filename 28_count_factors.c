#include <stdio.h>
#include <math.h>

int solution(int N) {
    int root;
    int i;
    int count = 0;

    root = (int) sqrt((double) N);
    if (root * root == N) {
        count++;
    } else {
        root++;
    }

    for (i = 1; i < root; i++) {
        if (N % i == 0) {
            count += 2;
        }
    }

    return count;
}

int main() {
    int N = 24;

    printf("Result: %d\n", solution(N));

    return 0;
}
