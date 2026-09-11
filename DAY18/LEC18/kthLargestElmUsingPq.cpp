#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);

        if(pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}
//t.c = O(nlogk)
//s.c = O(k)

int main() {
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 4;

    cout << kthLargest(arr, k);

    return 0;
}