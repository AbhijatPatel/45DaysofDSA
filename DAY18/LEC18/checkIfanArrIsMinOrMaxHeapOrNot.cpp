#include <bits/stdc++.h>
using namespace std;

//for max heap.

// bool isMaxHeap(vector<int>& arr) {
//     int n = arr.size();

//     for (int i = 0; i < n/ 2; i++) {
//         int left = 2 * i + 1;
//         int right = 2 * i + 2;

//         if (left < n && arr[i] < arr[left])
//             return false;

//         if (right < n && arr[i] < arr[right])
//             return false;
//     }

//     return true;
// }

//for min heap.

bool isMinHeap(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n / 2; i++) {// n/2 - from where leaf node start but we only consider non-leaf node.
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[i] < arr[left])
            return false;

        if (right < n && arr[i] < arr[right])
            return false;
    }

    return true;
}

int main() {
    vector<int> arr = {90, 70, 80, 20, 50};

    //  if (isMaxHeap(arr))
    if (isMinHeap(arr))
        cout << "Min Heap";
    else
        cout << "Not a Min Heap";

    return 0;
}