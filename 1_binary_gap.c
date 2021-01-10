#include <stdio.h>

int solution(int N) {
    int i;
    int max = 0;
    int counter = 0;
    char one = 1;
    char gap_started = 0;

    for (i = 0; i < sizeof(int) * 8; i++) {
        if ((N >> i) & one == 1) {
            if (gap_started) {
                max = counter > max ? counter : max;
                counter = 0;
            } else {
                gap_started = 1;
            }
        } else {
            if (gap_started) {
                counter++;
            }
        }
    }

    return max;
}

int main() {
    printf("Result: %d\n", solution(15));

    return 0;
}
