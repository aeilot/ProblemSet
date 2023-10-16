#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

long long Ni[220], Go[220];
long long dp[220][6201];

int main() {
    int n, k;
    cin >> n >> k;
    int maxv = 0;
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        long long b = a;
        while (a % 5 == 0) {
            a /= 5;
            Go[i]++;
        }
        maxv += Go[i];
        while (b % 2 == 0) {
            b /= 2;
            Ni[i]++;
        }
    }
    memset(dp, -0x3f3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= 1; j--) {
            for (int v = maxv; v >= Go[i]; v--) {
                dp[j][v] = max(dp[j][v], dp[j - 1][v - Go[i]] + Ni[i]);
            }
        }
    }
    long long ans = 0;
    for (long long v = maxv; v >= 0; v--) {
        ans = max(ans, min(dp[k][v], v));
    }
    cout << ans << endl;
    return 0;
}
