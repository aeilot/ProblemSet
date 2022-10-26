#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long MAP[1010][1010];
long long DP[1010][1010][2];
int n, m;

long long getDP(int i, int j) {
    return max(DP[i][j][0], DP[i][j][1]);// 0: UP, 1: DOWN
}

int main() {
    // Type your code here
    // m,n 看清楚顺序!!!
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            DP[i][j][0] = DP[i][j][1] = (int) (-1e18);
        }
    }
    DP[1][1][0] = DP[1][1][1] = MAP[1][1];
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (i == 1 && j == 1) continue;
            DP[i][j][0] = max(DP[i - 1][j][0], getDP(i, j - 1)) + MAP[i][j];
        }
        for (int i = n; i >= 1; i--) {
            DP[i][j][1] = max(getDP(i, j - 1), DP[i + 1][j][1]) + MAP[i][j];
        }
    }
    cout << DP[n][m][0] << endl;
    return 0;
}