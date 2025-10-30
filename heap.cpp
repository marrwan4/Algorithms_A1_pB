#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

enum HeapType {
    MAX_HEAP,
    MIN_HEAP
};

template <typename T>
class Heap {
private:
    T* heap;
    int size;
    HeapType type = MAX_HEAP;
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
    void heapify(int index) {
        int extreme = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (type == MAX_HEAP) {
            if (left < size && heap[left] > heap[extreme]) {
                extreme = left;
            }
            if (right < size && heap[right] > heap[extreme]) {
                extreme = right;
            }
        } else {
            if (left < size && heap[left] < heap[extreme]) {
                extreme = left;
            }
            if (right < size && heap[right] < heap[extreme]) {
                extreme = right;
            }
        }
        if (extreme != index) {
            swap(heap[index], heap[extreme]);
            heapify(extreme);
        }
    }
    T search_leaves_for_anti_extreme() {
        if (size == 0) {
            throw runtime_error("Heap is empty!");
        }
        T anti_extreme = heap[size / 2];
        for (int i = size / 2 + 1; i < size; i++) {
            if (type == MAX_HEAP) {
                if (heap[i] < anti_extreme) {
                    anti_extreme = heap[i];
                }
            } else {
                if (heap[i] > anti_extreme) {
                    anti_extreme = heap[i];
                }
            }
        }
        return anti_extreme;
    }
    T extract_extreme() {
        if (size == 0) {
            throw runtime_error("Heap is empty!");
        }
        T extreme = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return extreme;
    }
public:
    Heap(int arraySize) : size(0) {
        heap = new T[arraySize];
    }
    T peek() const {
        if (size == 0) {
            throw runtime_error("Heap is empty!");
        }
        return heap[0];
    }
    int getSize() {
        return size;
    }
    bool is_empty() {
        return size == 0;
    }
    void setType(HeapType t) {
        type = t;
    }
    void insert(const T& item) {
        int index = size;
        heap[index] = item;
        size++;
        if (type == MAX_HEAP) {
            while (index != 0 && heap[(index - 1) / 2] < heap[index]) {
                swap(heap[index], heap[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        } else {
            while (index != 0 && heap[(index - 1) / 2] > heap[index]) {
                swap(heap[index], heap[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        }
    }
    void print_heap() const {
        if (size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                cout << "[ ";
            }
            cout << heap[i];
            if (i == size - 1) {
                cout << " ]";
            } else {
                cout << ", ";
            }
        }
        cout << endl;
    }
    void setHeapType(HeapType t) {
        type = t;
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }
    T extract_max() {
        if (size == 0) {
            throw runtime_error("Heap is empty!");
        }
        if (type != MAX_HEAP) {
            T anti_extreme = search_leaves_for_anti_extreme();
            return anti_extreme;
        }
        return extract_extreme();
    }
    T extract_min() {
        if (size == 0) {
            throw runtime_error("Heap is empty!");
        }
        if (type != MIN_HEAP) {
            T anti_extreme = search_leaves_for_anti_extreme();
            return anti_extreme;
        }
        return extract_extreme();
    }
    static T* heapSort(T arr[], int n) {
        if (n <= 1) return arr;
        auto siftDown = [&](int start, int end) {
            int root = start;
            while (true) {
                int child = 2 * root + 1; // left child
                if (child > end) break;
                if (child + 1 <= end && arr[child] < arr[child + 1]) {
                    child++;
                }
                if (arr[root] < arr[child]) {
                    T tmp = arr[root];
                    arr[root] = arr[child];
                    arr[child] = tmp;
                    root = child;
                } else {
                    break;
                }
            }
        };
        // Build max-heap
        for (int start = n / 2 - 1; start >= 0; --start) {
            siftDown(start, n - 1);
        }
        // Extract elements from heap one by one
        for (int end = n - 1; end > 0; --end) {
            T tmp = arr[end];
            arr[end] = arr[0];
            arr[0] = tmp;
            siftDown(0, end - 1);
        }
        return arr;
    }
    ~Heap() {
        delete[] heap;
    }
};

template <typename T>
struct PQNode {
    int priority;
    T value;
    bool operator<(const PQNode& other) const { return priority < other.priority; }
    bool operator>(const PQNode& other) const { return priority > other.priority; }
    friend ostream& operator<<(ostream& os, const PQNode& n) {
        os << "(" << n.priority << ", " << n.value << ")";
        return os;
    }
};

template <typename T>
class PriorityQueue {
private:
    Heap<PQNode<T>> heap;
public:
    explicit PriorityQueue(int capacity) : heap(capacity) {
        heap.setType(MAX_HEAP);
    }
    void insert(const T& value, int priority) {
        heap.insert(PQNode<T>{priority, value});
    }
    T extractHighestPriority() {
        PQNode<T> node = heap.extract_max();
        return node.value;
    }
    bool isEmpty() { return heap.is_empty(); }
};

#ifndef UNIT_TEST
int main() {
    while (true) {
        cout << "Choose an option (0 to exit):\n";
        cout << "1) Heap Sort (integers)\n";
        cout << "2) Priority Queue (integers)\n";
        cout << "Enter choice: ";
        int choice;
        if (!(cin >> choice)) return 0;
        if (choice == 0) break;
        if (choice == 1) {
            cout << "Enter number of elements: ";
            int n; cin >> n;
            if (n <= 0) { cout << "Nothing to sort.\n"; continue; }
            vector<int> v(n);
            cout << "Enter " << n << " integers:\n";
            for (int i = 0; i < n; ++i) cin >> v[i];
            // Use in-place heap sort
            Heap<int>::heapSort(v.data(), n);
            cout << "Sorted: ";
            for (int i = 0; i < n; ++i) {
                cout << v[i] << (i + 1 == n ? '\n' : ' ');
            }
        } else if (choice == 2) {
            cout << "Enter capacity of priority queue: ";
            int cap; cin >> cap;
            PriorityQueue<int> pq(cap);
            cout << "Enter number of items to insert: ";
            int k; cin >> k;
            for (int i = 0; i < k; ++i) {
                int value, priority;
                cout << "Value and Priority for item " << (i + 1) << ": ";
                cin >> value >> priority;
                pq.insert(value, priority);
            }
            cout << "Extracting by highest priority: ";
            bool first = true;
            while (!pq.isEmpty()) {
                int val = pq.extractHighestPriority();
                if (!first) cout << ' ';
                cout << val;
                first = false;
            }
            cout << '\n';
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
#endif