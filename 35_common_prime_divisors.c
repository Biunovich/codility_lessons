#include <stdio.h>

inline static int
gcd(int a, int b) {
    int mod = a % b;

    if (mod == 0) {
        return b;
    }

    return gcd(b, mod);
}

inline static int
check(int a, int gcdAB) {
    int rest = a / gcdAB;

    while (gcdAB % rest != 0) {
        int tmp = gcd(gcdAB, rest);

        if (tmp == 1) {
            return 0;
        }

        rest /= tmp;
    }

    return 1;
}

inline static int
is_equal(int a, int b) {
    int GCD;

    if (a == b) {
        return 1;
    }

    GCD = a > b ? gcd(a, b) : gcd(b, a);

    if (GCD == 1) {
        return 0;
    }

    return check(a, GCD) && check(b, GCD);
}

int solution(int A[], int B[], int Z) {
    int i;
    int result = 0;

    for (i = 0; i < Z; i++) {
        if (is_equal(A[i], B[i])) {
            result++;
        }
    }

    return result;
}

int main() {
    int A[] = { 15, 10, 3 };
    int B[] = { 75, 30, 5 };

    printf("Result: %d\n", solution(A, B, 2));

    return 0;
}
