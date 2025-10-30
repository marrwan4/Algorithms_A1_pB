#define UNIT_TEST
#include "heap.cpp"
#include <cassert>
#include <cstring>

int main() {
    // heapSort on integers
    {
        int arr[] = {5, 1, 9, 3, 7, 2, 8, 4, 6, 0};
        int expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        Heap<int>::heapSort(arr, 10);
        for (int i = 0; i < 10; ++i) {
            assert(arr[i] == expected[i]);
        }
    }

    // PriorityQueue: higher priority first
    {
        PriorityQueue<int> pq(10);
        pq.insert(100, 1);
        pq.insert(200, 5);
        pq.insert(300, 3);
        int first = pq.extractHighestPriority();
        int second = pq.extractHighestPriority();
        int third = pq.extractHighestPriority();
        assert(first == 200);
        assert(second == 300);
        assert(third == 100);
        assert(pq.isEmpty());
    }

    // heapSort stability not required; test already ensures correct order

    return 0;
}


