#include <bits/stdc++.h>
using namespace std;

double power(double x, long long n) {
    if (n == 0)
        return 1.0;

    double half = power(x, n / 2);

    if (n % 2 == 0) {
        return half * half;
    }
    else {
        return half * half * x;
    }
}

double myPow(double x, int n) {
    long long N = n;

    if (N < 0) {
        N = -N;
        x = 1 / x;
    }

    return power(x, N);
}

int main() {
    double x;
    int n;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter n: ";
    cin >> n;

    double result = myPow(x, n);

    cout << "Answer: " << result << endl;

    return 0;
}