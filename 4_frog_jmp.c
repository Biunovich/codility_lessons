#include <stdio.h>

int solution(int X, int Y, int D) {
    int r;

    r = Y - X;
    return r % D == 0 ? r / D : (r / D) + 1;
}

int main() {
    printf("Result: %d\n", solution(15, 25, 5));

    return 0;
}
