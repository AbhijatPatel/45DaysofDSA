#include <bits/stdc++.h>
using namespace std;

//brute force approach

// int BuySellStocks(vector<int> &arr, int n) {

//     int maxProfit = 0;

//     for(int i = 0; i < n; i++) {

//         for(int j = i + 1; j < n; j++) {

//             int profit = arr[j] - arr[i];

//             maxProfit = max(maxProfit, profit);
//         }
//     }

//     return maxProfit;
// }

//optimized approach

int BuySellStocks(vector<int> &arr, int n) {

    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {

        minPrice = min(minPrice, arr[i]);

        int profit = arr[i] - minPrice;

        maxProfit = max(maxProfit, profit);

        
    }

    return maxProfit;
}

int main() {

    vector<int> arr = {7,1,5,3,6,4};

    cout << BuySellStocks(arr, arr.size());
}