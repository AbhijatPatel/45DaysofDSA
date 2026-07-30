#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(double dist, vector<int> &arr)
{
    int cnt = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        double gap = arr[i] - arr[i - 1];

        int numberInBetween = gap / dist;

        if (gap == numberInBetween * dist)
            numberInBetween--;

        cnt += numberInBetween;
    }

    return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();

    double low = 0;
    double high = 0;

    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (double)(arr[i + 1] - arr[i]));
    }

    double diff = 1e-6;

    while (high - low > diff)
    {
        double mid = (low + high) / 2.0;

        int cnt = numberOfGasStationsRequired(mid, arr);

        if (cnt > k)
            low = mid;
        else
            high = mid;
    }

    return high;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int k = 9;

    cout << fixed << setprecision(6);
    cout << minimiseMaxDistance(arr, k);

    return 0;
}