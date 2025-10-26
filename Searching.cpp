#include <list>
#include <iostream>
#include <chrono>
#include <functional>

using namespace std;
using namespace std::chrono;

class Searching {
public:
    static long long int SequentialSearch(const std::list<long long int>& list, long long int target) {
        int index = 0;
        for (const long long it : list) {
            if (it == target) {
                return index;
            }
            index++;
        }
        return -1; // Target not found
    }
    static long long int BinarySearch(const std::list<long long int>& list, long long int target) {
        long long int l =0, r = list.size();
        while (l <= r) {
            const long long int mid = l + (r - l) / 2;
            auto it = list.begin();
            advance(it, mid);
            if (*it == target) {
                return mid;
            }else if (*it > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1; // Target not found
    }
    static long long int SequentialRecursiveSearch(const std::list<long long int>& list, long long int target) {
        // I should implement sequential recursive search here
        return -1; // Target not found
    }
    static long long int BinaryRecursiveSearch(const std::list<long long int>& list, long long int target) {
        // doma should implement binary recursive search here
        return -1; // Target not found
    }
    void static highResolutionClock(function<long long int(const std::list<long long int>&, long long int)> func, const std::list<long long int>& list, long long int target) {
        auto start = high_resolution_clock::now();
        long long int result = func(list, target);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        cout << "Result: " << result << ", Time taken by function: " << duration.count() << " nanoseconds" << " ";
    }
};

int main() {
    while (true) {
        cout << "Enter the size of the list (or a negative number to exit): ";
        long long int size;
        cin >> size;
        if (size < 0) break;
        list<long long int> myList;
        for (long long int i = 0; i < size; ++i) {
            myList.push_back(i * 2); // Even numbers
        }
        cout << "Enter the target number to search for: ";
        long long int target;
        cin >> target;

        cout << "Searching for " << target << " in the list of size " << size << " using different methods:" << endl;
        Searching::highResolutionClock(Searching::SequentialSearch, myList, target);cout << "by Sequential Search Method" << endl;
        Searching::highResolutionClock(Searching::BinarySearch, myList, target);cout << "by Binary Search Method" << endl;
        Searching::highResolutionClock(Searching::SequentialRecursiveSearch, myList, target);cout << "by Sequential Recursive Search Method" << endl;
        Searching::highResolutionClock(Searching::BinaryRecursiveSearch, myList, target);cout << "by Binary Recursive Search Method" << endl;
    }
    return 0;
}