#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> sorted = arr;

    sort(sorted.begin(), sorted.end());

    map<int, int> mp;

    int rank = 1;

    for (int i = 0; i < n; i++) {
        if (mp.find(sorted[i]) == mp.end()) {
            mp[sorted[i]] = rank;
            rank++;
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = mp[arr[i]];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
//Time Complexity: O(n log n)
//Space Complexity: O(n)
