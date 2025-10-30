#define UNIT_TEST
#include "Fibonacci.cpp"
#include <cassert>

static long long expectedFib(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    long long a = 0, b = 1;
    for (long long i = 2; i <= n; ++i) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    // Sanity checks for small n
    for (int n = 0; n <= 20; ++n) {
        long long e = expectedFib(n);
        long long r1 = Fibonacci::Recursive(n);
        long long r2 = Fibonacci::MatrixMultiplication(n);
        long long r3 = Fibonacci::DynamicProgramming(n);
        assert(r1 == e);
        assert(r2 == e);
        assert(r3 == e);
        assert(r1 == r2 && r2 == r3);
    }

    // Larger n for non-recursive methods
    for (int n : {30, 40, 50}) {
        long long e = expectedFib(n);
        long long r2 = Fibonacci::MatrixMultiplication(n);
        long long r3 = Fibonacci::DynamicProgramming(n);
        assert(r2 == e);
        assert(r3 == e);
    }

    return 0;
}


