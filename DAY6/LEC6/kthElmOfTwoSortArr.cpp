#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int> &arr2, int k)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    // binary search always perform on the smaller array
    if (n1 > n2)
        return kthElement(arr2, arr1, k);

    // Binary search range
    int low = max(0, k - n2);
    int high = min(k, n1);

    while (low <= high)
    {
        // Number of elements taken from arr1
        int cut1 = (low + high) / 2;

        // Remaining elements taken from arr2
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];

        int r1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : arr2[cut2];

        //we found correct partition
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }

        else
        {
            low = cut1 + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};

    int k = 5;

    cout << "Kth Element = " << kthElement(arr1, arr2, k);

    return 0;
}