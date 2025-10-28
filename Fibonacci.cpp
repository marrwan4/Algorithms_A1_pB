#include <iostream>
#include <functional>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;
using namespace std::chrono;

class Fibonacci {
public:
    static long long int Recursive(long long int position) {
        if (position == 0 || position == 1) {
            return 1;
        }
        return Recursive(position - 1) + Recursive(position - 2);
    }
    struct Matrix {
        long long a, b, c, d;
    };
    static Matrix MatrixMultiply(const Matrix &matrixA, const Matrix &MatrixB) {
        Matrix result;
        result.a = matrixA.a * MatrixB.a + matrixA.b * MatrixB.c;
        result.b = matrixA.a * MatrixB.b + matrixA.b * MatrixB.d;
        result.c = matrixA.c * MatrixB.a + matrixA.d * MatrixB.c;
        result.d = matrixA.c * MatrixB.b + matrixA.d * MatrixB.d;
        return result;
    }
    static Matrix MatrixPower(Matrix base, long long n) {
        if (n == 1) return base;
        if (n % 2 == 0) {
            Matrix half = MatrixPower(base, n / 2);
            return MatrixMultiply(half, half);
        } else {
            return MatrixMultiply(base, MatrixPower(base, n - 1));
        }
    }
    static long long int MatrixMultiplication(long long int position) {
        if (position == 0) return 0;
        if (position == 1) return 1;
        Matrix fibMatrix = {1, 1, 1, 0};
        Matrix result = MatrixPower(fibMatrix, position - 1);
        return result.a;
    }
    static long long int DynamicProgramming(long long int position) {
        // doma should implement dynamic programming method here
        return 0; // Placeholder
    }
    void static highResolutionClock(function<long long(long long)> func, long long int position) {
        auto start = high_resolution_clock::now();
        long long result = func(position);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Result: " << result << ", Time taken by function: " << duration.count() << " nanoseconds" << " ";
    }
};

int main() {
    while (true) {
        cout << "Enter the position of the Fibonacci number you want to calculate (or a negative number to exit): ";
        long long int position;
        cin >> position;
        if (position < 0) break;
        cout << "Calculating Fibonacci number at position " << position << " using different methods:" << endl;
        Fibonacci::highResolutionClock(Fibonacci::Recursive, position);cout << "by Recursive Method" << endl;
        Fibonacci::highResolutionClock(Fibonacci::MatrixMultiplication, position);cout << "by Matrix Multiplication Method" << endl;
        Fibonacci::highResolutionClock(Fibonacci::DynamicProgramming, position);cout << "by Dynamic Programming Method" << endl;
    }
    return 0;
}