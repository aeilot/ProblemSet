#include <cstdio>
#include <iostream>

using namespace std;

int MAP[13];
int stj[2000];
int cnt = 0;
long long DP[13][2000];

int main() {
    // Type your code here
    int m, n;
    cin >> m >> n;
    MAP[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int t;
            cin >> t;
            t ^= 1;
            MAP[i] = (MAP[i] << 1) + t;
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        if (i & (i << 1)) continue;
        if (i & (i >> 1)) continue;
        stj[++cnt] = i;
    }
    for (int i = 1; i <= cnt; i++) {
        if (stj[i] & MAP[1]) continue;  // 注意！
        DP[1][i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= cnt; j++) {
            if (stj[j] & MAP[i]) {
                continue;
            }
            for (int k = 1; k <= cnt; k++) {
                if (stj[j] & stj[k] || stj[k] & MAP[i - 1]) continue;
                DP[i][j] += DP[i - 1][k];
                DP[i][j] %= 100000000;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= cnt; i++) {
        ans = (ans + DP[m][i]) % 100000000;
    }
    cout << ans << endl;
    return 0;
}