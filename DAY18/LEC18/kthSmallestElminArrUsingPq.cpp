#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    priority_queue<int> pq;

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
    vector<int> arr = {7,10,4,20,15};
    int k = 4;

    cout << kthSmallest(arr, k);

    return 0;
}