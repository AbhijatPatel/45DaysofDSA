#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int n = arr.size();

    vector<int> missing;

    for (int i = 0; i < n; i++)
    {
        missing.push_back((arr[i] - 1) - i);
    }

    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid =(low+high)/2;

        if (missing[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return arr[high] + (k - missing[high]);
}

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    cout << "Kth Missing Positive Number = "
         << findKthPositive(arr, k);

    return 0;
}