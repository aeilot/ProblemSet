#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

long long dp[11][2000][100] = {0};

int sta[2000], stj[2000];
int cnt = 0;
int n, kn;

void dfs(int x, int num, int cur) {
    if (cur >= n) {
        sta[++cnt] = num;
        stj[cnt] = x;
        return;
    }
    dfs(x, num, cur + 1);
    dfs((1 << cur) + x, num + 1, cur + 2);
}

int main() {
    cin >> n >> kn;
    dfs(0, 0, 0);
    for (int i = 1; i <= cnt; i++) {
        dp[1][i][sta[i]] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= cnt; j++) {
            for (int k = 1; k <= cnt; k++) {
                if (stj[j] & stj[k]) continue;
                if ((stj[j] << 1) & stj[k]) continue;
                if (stj[j] & (stj[k] << 1)) continue;
                for (int l = kn; l >= sta[j]; l--) {
                    dp[i][j][l] += dp[i - 1][k][l - sta[j]];
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= cnt; i++) {
        ans += dp[n][i][kn];
    }
    cout << ans << endl;
    return 0;
}