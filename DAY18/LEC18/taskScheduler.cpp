#include <bits/stdc++.h>
using namespace std;

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char task : tasks) {
            freq[task - 'A']++;
        }

        priority_queue<int> pq;

        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int time = 0;

        while(!pq.empty()) {
            vector<int> temp;

            for(int i = 0; i <= n; i++) {
                if(!pq.empty()) {
                    int count = pq.top();
                    pq.pop();

                    count--;

                    if(count > 0) {
                        temp.push_back(count);
                    }
                }

                time++;

                if(pq.empty() && temp.empty()) {
                    break;
                }
            }

            for(int count : temp) {
                pq.push(count);
            }
        }

        return time;
    }

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    cout << leastInterval(tasks, n);

    return 0;
}
// Time  = O(N log K)
// Space = O(K)