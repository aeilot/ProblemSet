#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int MAP[51][51];
int dp[51][51][51][51];

int main() {
    // Type your code here
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> MAP[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    // 调整后，相当于同起点两条路
    for (int a = 1; a <= m; a++) {
        for (int b = 1; b <= n; b++) {
            for (int c = 1; c <= m; c++) {
                for (int d = b + 1; d <= n; d++) {// 两路不相交， 一上一下
                    dp[a][b][c][d] =
                            max(max(dp[a - 1][b][c - 1][d], dp[a - 1][b][c][d - 1]),
                                max(dp[a][b - 1][c - 1][d],
                                    dp[a][b - 1][c][d - 1])) +
                            MAP[a][b] + MAP[c][d];
                }
            }
        }
    }
    cout << dp[m][n - 1][m - 1][n] << endl;
    return 0;
}