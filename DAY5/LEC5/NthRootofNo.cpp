#include <bits/stdc++.h>
using namespace std;

int nthRoot(int n, int m){
    int low = 1, high = m;

    while(low<=high){
        int mid = (low+high)/2;
         long long power = 1;
        for(int i = 0; i < n; i++){
            power *= mid;
        }
        if(power == m)
        return mid;

        else if(power>m)
        high = mid-1;

        else
        low = mid+1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the value of n in Nth root" << " " << endl;
    cin >> n;

    int m;
    cout << "Enter No.  ";
    cin >>m;

    cout << nthRoot(n,m);
    return 0;
}