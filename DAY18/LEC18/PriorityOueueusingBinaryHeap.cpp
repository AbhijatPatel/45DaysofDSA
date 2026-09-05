#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int H[1000];
    int s = -1;// current index value of the array H[].

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void shiftUp(int i) {
        while (i > 0 && H[parent(i)] < H[i]) {
            swap(H[parent(i)], H[i]);
            i = parent(i);
        }
    }

    void shiftDown(int i) {
        while (true) {
            int left = leftChild(i);
            int right = rightChild(i);
            int largest = i;

            if (left <= s && H[left] > H[largest])
                largest = left;

            if (right <= s && H[right] > H[largest])
                largest = right;

            if (largest == i)
                break;

            swap(H[i], H[largest]);
            i = largest;
        }
    }

    void insert(int x) {
        s++;
        H[s] = x;
        shiftUp(s);
    }

    int extractMax() {
        if (s == -1)
            return -1;

        int ans = H[0];

        H[0] = H[s];
        s--;

        if (s >= 0)
            shiftDown(0);

        return ans;
    }

    int getMax() {
        if (s == -1)
            return -1;

        return H[0];
    }

    void printHeap() {
        for (int i = 0; i <= s; i++)
            cout << H[i] << " ";

        cout << endl;
    }
};

int main() {
    Solution h;

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(35);

    cout << "Max Heap: ";
    h.printHeap();

    cout << "Maximum: " << h.getMax() << endl;

    cout << "Extracted: " << h.extractMax() << endl;

    cout << "After deletion: ";
    h.printHeap();

    return 0;
}