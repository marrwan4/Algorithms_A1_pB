#include <iostream>

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
public:
    Heap(int arraySize) : size(0) {
        heap = new T[arraySize];
    }
    T peek() const {
        if (size == 0) {
            return "Heap is empty!";
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
        if (size == 0) {
            heap[0] = item;
            size++;
        } else if (type == MAX_HEAP) {
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
            cout << heap[i].getName();
            if (i == size - 1) {
                cout << " ]";
            } else {
                cout << ", ";
            }
        }
        cout << endl;
    }
    // todo extract max/min , switch heap type
    static T* heapSort(T arr[], int n) {
        // doma should implement heap sort here
    }
    ~Heap() {
        delete[] heap;
    }
};

int main() {
    return 0;
}