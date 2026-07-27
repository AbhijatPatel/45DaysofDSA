#include <bits/stdc++.h>
using namespace std;

// Function to check whether it is possible to make m bouquets
bool isPossible(vector<int> &bloomDay, int m, int k, int day)
{
    int cnt = 0;
    int totalBouquets = 0;

    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
        {
            cnt++;

            if (cnt == k)
            {
                totalBouquets++;
                cnt = 0; 

                if (totalBouquets == m)
                    return true;
            }
        }
        else
        {
            cnt = 0;
        }
    }

    return false;
}


int minDays(vector<int> &bloomDay, int m, int k){

    int minElm = *min_element(bloomDay.begin(), bloomDay.end());
    int maxElm = *max_element(bloomDay.begin(), bloomDay.end());

    int low = minElm ,high = maxElm;

    int ans = -1;

    while (low<= high)
    {
        int mid =(low+high) / 2;

        bool check = isPossible(bloomDay, m, k, mid);

        if (check == true)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};

    int m = 3;
    int k = 1;

    cout << "Minimum Days = " << minDays(bloomDay, m, k);

    return 0;
}