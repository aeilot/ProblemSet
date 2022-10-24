#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int dp[41][41][41][41];
int map[351];
int cnt[5];

int calc(int a, int b, int c, int d) { return a + 2 * b + 3 * c + 4 * d; }

int main() {
    // Type your code here
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        map[i] = tmp;
    }
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
    }
    dp[0][0][0][0] = map[0];
    dp[1][0][0][0] = map[1];
    dp[0][1][0][0] = map[2];
    dp[0][0][1][0] = map[3];
    dp[0][0][0][1] = map[4];
    for (int a = 0; a <= cnt[1]; a++) {
        for (int b = 0; b <= cnt[2]; b++) {
            for (int c = 0; c <= cnt[3]; c++) {
                for (int d = 0; d <= cnt[4]; d++) {
                    int& tt = dp[a][b][c][d];
                    if (a >= 1)
                        tt = max(tt, dp[a - 1][b][c][d] +
                                         map[calc(a - 1, b, c, d) + 1]);
                    if (b >= 1)
                        tt = max(tt, dp[a][b - 1][c][d] +
                                         map[calc(a, b - 1, c, d) + 2]);
                    if (c >= 1)
                        tt = max(tt, dp[a][b][c - 1][d] +
                                         map[calc(a, b, c - 1, d) + 3]);
                    if (d >= 1)
                        tt = max(tt, dp[a][b][c][d - 1] +
                                         map[calc(a, b, c, d - 1) + 4]);
                }
            }
        }
    }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
    return 0;
}