#include <bits/stdc++.h>
using namespace std;

vector<int> maximumSumCombinations(vector<int> A, vector<int> B, int C) {
    int n = A.size();

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    priority_queue<pair<int, pair<int, int>>> maxHeap;
    set<pair<int, int>> visited;

    maxHeap.push({A[0] + B[0], {0, 0}});
    visited.insert({0, 0});

    vector<int> answer;

    while (C-- && !maxHeap.empty()) {
        auto current = maxHeap.top();
        maxHeap.pop();

        int sum = current.first;
        int i = current.second.first;
        int j = current.second.second;

        answer.push_back(sum);

        if (i + 1 < n && !visited.count({i + 1, j})) {
            maxHeap.push({
                A[i + 1] + B[j],
                {i + 1, j}
            });

            visited.insert({i + 1, j});
        }

        if (j + 1 < n && !visited.count({i, j + 1})) {
            maxHeap.push({
                A[i] + B[j + 1],
                {i, j + 1}
            });

            visited.insert({i, j + 1});
        }
    }

    return answer;
}

int main() {
    vector<int> A = {3, 2};
    vector<int> B = {1, 4};
    int C = 2;

    vector<int> answer = maximumSumCombinations(A, B, C);

    cout << "Maximum Sum Combinations: ";

    for (int value : answer) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}