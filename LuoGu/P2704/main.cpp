#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int MAP[110];
int n, m;
long long DP[110][105][105];
int stx[900], sta[900];
int cnt = 0;

bool check(int x, int y) { return stx[y] & stx[x]; }

int main() {
    // Type your code here
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            int fg = 0;
            if (x == 'H') {
                fg = 1;
            }
            MAP[i] = (MAP[i] << 1) + fg;
        }
    }
    stx[++cnt] = 0;
    for (int i = 1; i < (1 << m); i++) {
        if (i & (i << 1)) continue;
        if (i & (i << 2)) continue;
        if (i & (i >> 1)) continue;
        if (i & (i >> 2)) continue;
        stx[++cnt] = i;
        int x = i;
        while (x) {// popcount
            sta[cnt] += x & 1;
            x >>= 1;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        if (stx[i] & MAP[1]) continue;
        DP[1][i][0] = sta[i];
    }
    for (int i = 1; i <= cnt; i++) {
        if (stx[i] & MAP[2]) continue;
        for (int j = 1; j <= cnt; j++) {
            if (check(i, j) || (stx[j] & MAP[1])) continue;
            DP[2][i][j] = DP[1][j][0] + sta[i];
        }
    }
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= cnt; j++) {// current
            if (stx[j] & MAP[i]) continue;
            for (int k = 1; k <= cnt; k++) {// prev
                if (stx[k] & MAP[i - 1] || check(k, j)) continue;
                for (int l = 1; l <= cnt; l++) {// prev*2
                    if (check(j, l) || check(l, k) || (stx[l] & MAP[i - 2]))
                        continue;
                    DP[i][j][k] = max(DP[i][j][k], DP[i - 1][k][l] + sta[j]);
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j <= cnt; j++) {// n = 1 时 j = 0
            ans = max(DP[n][i][j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}