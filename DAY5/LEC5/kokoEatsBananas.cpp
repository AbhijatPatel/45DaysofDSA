#include <bits/stdc++.h>
using namespace std;

int calculateHours(vector<int> &arr, int speed)
{
    int totalHours = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        totalHours += ceil((double)arr[i] / speed);
    }

    return totalHours;
}

int kokoEatingBanana(vector<int> &arr, int h)
{
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());

    while (low <= high)
    {
        int mid =(low+high) / 2;

        int totalHours = calculateHours(arr, mid);

        if (totalHours <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    vector<int> arr = {3, 6, 7, 11};
    int h = 8;

    cout << kokoEatingBanana(arr, h);
}