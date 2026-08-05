#include <bits/stdc++.h>
using namespace std;

int atMostK(vector<int> & nums,int k){
    if(k<0)
    return 0;

    map<int,int> mp;
    int l=0,r=0;
    int n = nums.size();
    int cnt =0;

    while(r<n){
        mp[nums[r]]++;

        while(mp.size()>k && l<=r){
            mp[nums[l]]--;

            if(mp[nums[l]]==0)
            mp.erase(nums[l]);
            l++;
        }
        cnt += (r-l+1);
        r++;
    }
    return cnt;
}
int subarraysWithKDistinct(vector<int> & nums,int k){
    return atMostK(nums,k)-atMostK(nums,k-1);
}
int main() {
    vector<int> nums = {1,2,1,2,3};
    int k = 2;

    cout <<subarraysWithKDistinct(nums,k);
    return 0;
}