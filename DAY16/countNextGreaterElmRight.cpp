#include <iostream>
#include <vector>
using namespace std;

vector<int> countGreater(vector<int> arr, vector<int> indices) {
    vector<int> ans;

    for (int index : indices) {
        int count = 0;

        for (int j = index + 1; j < arr.size(); j++) {
            if (arr[j] > arr[index]) {
                count++;
            }
        }

        ans.push_back(count);
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6};
    vector<int> indices = {0, 3};

    vector<int> ans = countGreater(arr, indices);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}