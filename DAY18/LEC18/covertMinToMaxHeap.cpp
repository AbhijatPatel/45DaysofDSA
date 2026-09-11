#include <bits/stdc++.h>
using namespace std;

    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && nums[left] > nums[largest]) {
            largest = left;
        }

        if(right < n && nums[right] > nums[largest]) {
            largest = right;
        }

        if(largest != i) {
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }

    vector<int> minToMaxHeap(vector<int> nums) {
        int n = nums.size();

        for(int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        return nums;
    }
    //t.c = O(n)
    //S.c = O(logn)

int main() {
   
    vector<int> nums = {10, 20, 15, 30, 40, 50};

    vector<int> ans = minToMaxHeap(nums);

    cout << "Max Heap: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}