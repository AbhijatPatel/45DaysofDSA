#include <iostream>
#include <vector>
#include<stack>
using namespace std;

//brute force

// vector<int> prices;

// int next(int price) {
//     prices.push_back(price);

//     int span = 1;
//     int i = prices.size() - 2;

//     while (i >= 0 && prices[i] <= price) {
//         span++;
//         i--;
//     }

//     return span;
// }

//optimized

    stack<pair<int, int>> st;
    
    int next(int price) {
        int span = 1;

        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        st.push({price, span});

        return span;
    }

int main() {
    cout << next(100) << " ";
    cout << next(80) << " ";
    cout << next(60) << " ";
    cout << next(70) << " ";
    cout << next(60) << " ";
    cout << next(75) << " ";
    cout << next(85) << endl;

    return 0;
}


