#include <cstdio>
#include <iostream>

using namespace std;

long long C(long long m, long long n) {
    long long opA = 1;
    for (long long k = m; k >= n; k--) {
        opA = opA * k % 998244353;
    }
    long long opB = 1;
    for (long long k = n; k >= 1; k--) {
        opB = opB * k % 998244353;
    }
    return opA * opB % 998244353;
}

long long pow(long long p, long long q) {
    if (p == 1) return 1;
    long long ans = 1;
    for (; q; q >>= 1) {
        if (q & 1 == 0) ans = ans * p % 998244353;
        p = p * p % 998244353;
    }
    return ans;
}

int main() {
    // Type your code here
    long long n, k;
    cin >> n >> k;
    for (int) return 0;
}