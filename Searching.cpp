#include <list>
#include <iostream>
#include <chrono>
#include <functional>

using namespace std::chrono;
using namespace std;

class Searching {
public:
    static long long int SequentialSearch(const list<long long int>& list, long long int target) {
        int index = 0;
        for (const long long it : list) {
            if (it == target) {
                return index;
            }
            index++;
        }
        return -1;
    }
    static long long int BinarySearch(const list<long long int>& list, long long int target) {
        long long int l = 0, r = static_cast<long long int>(list.size()) - 1;
        while (l <= r) {
            long long int mid = l + (r - l) / 2;
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
        return -1;
    }
    static long long int SequentialRecursiveSearch(const list<long long int>& list, long long int target) {
        if (list.empty()) {
            return -1;
        } else if (target == list.front()) {
            return 0;
        } else {
            std::list<long long int> sublist(list);
            sublist.pop_front();
            long long int result = SequentialRecursiveSearch(sublist, target);
            if (result == -1) {
                return -1;
            } else {
                return result + 1;
            }
        }
    }
    static long long int BinaryRecursiveSearchHelper(const list<long long int>& list, long long int target, long long int low, long long int high) {
        if (low > high) {
            return -1;
        }
        long long int mid = low + (high - low) / 2;
        auto it = list.begin();
        advance(it, mid);
        if (*it == target) {
            return mid;
        } else if (*it > target) {
            return BinaryRecursiveSearchHelper(list, target, low, mid - 1);
        } else {
            return BinaryRecursiveSearchHelper(list, target, mid + 1, high);
        }
    }
    static long long int BinaryRecursiveSearch(const list<long long int>& list, long long int target) {
        if (list.empty()) return -1;
        return BinaryRecursiveSearchHelper(list, target, 0, static_cast<long long int>(list.size()) - 1);
    }
    void static highResolutionClock(function<long long int(const list<long long int>&, long long int)> func, const list<long long int>& list, long long int target) {
        auto start = high_resolution_clock::now();
        long long int result = func(list, target);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        if (result != -1) {
            cout << "Target found at index: " << result << ". ";
        } else {
            cout << "Target not found. ";
        }
        cout << "Time taken by function: " << duration.count() << " nanoseconds" << endl;
    }
};

#ifndef UNIT_TEST
int main() {
    while (true) {
        cout << "Enter the size of the list (or a negative number to exit): ";
        long long int size;
        cin >> size;
        if (size < 0) break;
        list<long long int> myList;

        cout << "Choose input method:\n1) Manual\n2) Random\nEnter choice: ";
        int choice;
        cin >> choice;
        if (size > 0 && choice == 1) {
            cout << "Enter " << size << " elements (any integers):" << endl;
            for (long long int i = 0; i < size; ++i) {
            long long int val;
            cin >> val;
            myList.push_back(val);
            }
        } else {
            std::srand(static_cast<unsigned>(chrono::high_resolution_clock::now().time_since_epoch().count()));
            for (long long int i = 0; i < size; ++i) {
                long long int val = std::rand() % (static_cast<int>(size * 10 + 1));
                myList.push_back(val);
                cout << val << " ";
            }
            cout << endl;
        }
        myList.sort();
        cout << "list sorted." << endl;

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
#endif