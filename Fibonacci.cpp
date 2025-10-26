#include <iostream>
#include <functional>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Fibonacci {
public:
    static unsigned long long int Recursive(unsigned long long int position) {
        // fras should implement dynamic programming method here
        return 0; // Placeholder
    }
    static unsigned long long int MatrixMultiplication(unsigned long long int position) {
        // I should implement dynamic programming method here (maro)
        return 0; // Placeholder
    }
    static unsigned long long int DynamicProgramming(unsigned long long int position) {
        // doma should implement dynamic programming method here
        return 0; // Placeholder
    }
    void static highResolutionClock(function<unsigned long long(unsigned long long)> func, unsigned long long int position) {
        auto start = high_resolution_clock::now();
        unsigned long long result = func(position);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Result: " << result << ", Time taken by function: " << duration.count() << " nanoseconds" << " ";
    }
};

int main() {
    while (true) {
        cout << "Enter the position of the Fibonacci number you want to calculate (or a negative number to exit): ";
        unsigned long long int position;
        cin >> position;
        if (position < 0) break;
        cout << "Calculating Fibonacci number at position " << position << " using different methods:" << endl;
        Fibonacci::highResolutionClock(Fibonacci::Recursive, position);cout << "by Recursive Method" << endl;
        Fibonacci::highResolutionClock(Fibonacci::MatrixMultiplication, position);cout << "by Matrix Multiplication Method" << endl;
        Fibonacci::highResolutionClock(Fibonacci::DynamicProgramming, position);cout << "by Dynamic Programming Method" << endl;
    }
    return 0;
}