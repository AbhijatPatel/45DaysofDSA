#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    int *arr;
    int capacity;
    int size;

    MinHeap(int c) {
        size = 0;
        capacity = c;
        arr = new int[c];
    }

    ~MinHeap() {
        delete[] arr;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insertKey(int k) {
        if (size == capacity)
            return;

        int i = size;
        arr[i] = k;
        size++;

        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int extractMin() {
        if (size == 0)
            return -1;

        int ans = arr[0];

        arr[0] = arr[size - 1];
        size--;

        if (size > 0)
            MinHeapify(0);

        return ans;
    }

    void deleteKey(int i) {
        if (i < 0 || i >= size)
            return;

        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void decreaseKey(int i, int new_val) {
        if (i < 0 || i >= size)
            return;

        arr[i] = new_val;

        while (i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void MinHeapify(int i) {
        int l = left(i);
        int r = right(i);

        int smallest = i;

        if (l < size && arr[l] < arr[smallest])
            smallest = l;

        if (r < size && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            MinHeapify(smallest);
        }
    }

    int getMin() {
        if (size == 0)
            return -1;

        return arr[0];
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {

    MinHeap h(10);

    h.insertKey(10);
    h.insertKey(20);
    h.insertKey(5);
    h.insertKey(30);
    h.insertKey(2);
    h.insertKey(15);

    cout << "Min Heap: ";
    h.printHeap();

    cout << "Minimum: " << h.getMin() << endl;

    cout << "Extracted: " << h.extractMin() << endl;

    cout << "After Extract: ";
    h.printHeap();

    h.decreaseKey(2, 1);

    cout << "After Decrease Key: ";
    h.printHeap();

    h.deleteKey(2);

    cout << "After Delete: ";
    h.printHeap();

    return 0;
}