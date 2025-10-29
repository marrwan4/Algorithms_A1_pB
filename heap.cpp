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
    T search_leaves_for_anti_extreme() {
        if (size == 0) {
            return T("Heap is empty!");
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
            return T("Heap is empty!");
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
            return T("Heap is empty!");
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
    void setHeapType(HeapType t) {
        type = t;
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }
    T extract_max() {
        if (size == 0) {
            return T("Heap is empty!");
        }
        if (type != MAX_HEAP) {
            T anti_extreme = search_leaves_for_anti_extreme();
            return anti_extreme;
        }
        return extract_extreme();
    }
    T extract_min() {
        if (size == 0) {
            return T("Heap is empty!");
        }
        if (type != MIN_HEAP) {
            T anti_extreme = search_leaves_for_anti_extreme();
            return anti_extreme;
        }
        return extract_extreme();
    }
    static T* heapSort(T arr[], int n) {
        // doma should implement heap sort here
    }
    ~Heap() {
        delete[] heap;
    }
};

int main() {
}