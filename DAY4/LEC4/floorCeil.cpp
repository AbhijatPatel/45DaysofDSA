#include <bits/stdc++.h>
using namespace std;

pair<int,int> findFloorCeil(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;

    int floor = 0;
    int ceil = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
            return {k, k};

        else if (arr[mid] < k)
        {
            floor = arr[mid];
            low = mid + 1;
        }
        else
        {
            ceil = arr[mid];
            high = mid - 1;
        }
    }

    return {floor, ceil};
}

int main()
{
    vector<int> arr = {3,4,4,7,8,10};
    int k = 5;

    pair<int,int> ans = findFloorCeil(arr, arr.size(), k);

    cout << ans.first << " is floor and "<< ans.second << " is ceil" << endl;

    return 0;
}