#include <cstdio>
#include <iostream>

using namespace std;

long long quickpow(long long a, long long b) {
    long long ans = 1;
    for (; b; b >>= 1) {
        if (b & 1) ans = ans * a % 998244353;
        a = a * a % 998244353;
    }
    return ans;
}

long long C(int a, int b) {
    long long ans1 = 1;
    long long ans2 = 1;
    for (long long i = b; i >= 1; i--) {
        ans1 = ans1 * i;
    }
    for (long long i = a; i >= a - b + 1; i--) {
        ans2 = ans2 * i;
    }
    long long ans = ans2 / ans1;
    ans %= 998244353;
    return ans;
}

int main() {
    // Type your code here
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n, m, k;
        cin >> n >> m >> k;
        long long ans = 0;
        for (long long j = k; j <= n; j++) {
            ans += C(n, j) * quickpow(m - 1, n - j) % 998244353;
        }
        cout << ans << endl;
    }
    return 0;
}