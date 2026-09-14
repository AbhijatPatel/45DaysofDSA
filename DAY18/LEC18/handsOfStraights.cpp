#include <bits/stdc++.h>
using namespace std;


    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) {
            return false;
        }

        map<int, int> freq;

        for(int card : hand) {
            freq[card]++;
        }

        while(!freq.empty()) {
            int start = freq.begin()->first;

            for(int i = 0; i < groupSize; i++) {
                int card = start + i;

                if(freq.find(card) == freq.end()) {
                    return false;
                }

                freq[card]--;

                if(freq[card] == 0) {
                    freq.erase(card);
                }
            }
        }

        return true;
    }

int main() {

    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;

    cout << boolalpha << isNStraightHand(hand, groupSize);

    return 0;
}