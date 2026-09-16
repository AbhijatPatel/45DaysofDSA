#include <bits/stdc++.h>
using namespace std;

    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int> > pq;

        for(int stick : sticks) {
            pq.push(stick);
        }

        int totalCost = 0;

        while(pq.size() > 1) {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            int cost = first + second;

            totalCost += cost;

            pq.push(cost);
        }

        return totalCost;
    }

int main() {
    vector<int> sticks = {2, 4, 3};

    int answer = connectSticks(sticks);

    cout << "Minimum Cost: " << answer << endl;

    return 0;
}