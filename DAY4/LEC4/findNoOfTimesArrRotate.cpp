#include <bits/stdc++.h>
using namespace std;

int noOfTimesArrRotate(vector<int> &arr, int n)
{
    int low = 0, high = n - 1;

    int minElm = INT_MAX;
    int idx = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

    
        if (arr[low] <= arr[mid])
        {
            if (arr[low] < minElm)
            {
                minElm = arr[low];
                idx = low;
            }

            low = mid + 1;
        }
        else
        {
            if (arr[mid] < minElm)
            {
                minElm = arr[mid];
                idx = mid;
            }

            high = mid - 1;
        }
    }

    return idx;
}

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2,3};

    cout << noOfTimesArrRotate(arr, arr.size());

    return 0;
}