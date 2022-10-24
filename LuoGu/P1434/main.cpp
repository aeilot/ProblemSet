#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

long long MAP[105][105];
long long dp[105][105];
int r, c;

using namespace std;

struct pos {
    int i, j;
    long long val;

    bool operator<(const pos &a) const { return this->val > a.val; }
};

// ?: 边界判断去掉就对了？

int main(int argc, char *argv[]) {
    cin >> r >> c;
    priority_queue<pos> pq;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int m;
            cin >> m;
            MAP[i][j] = m;
            pos a;
            a.i = i;
            a.j = j;
            a.val = m;
            pq.push(a);
            dp[i][j] = 1;
        }
    }
    while (!pq.empty()) {
        pos t = pq.top();
        pq.pop();
        int x = t.i;
        int y = t.j;
        if (MAP[x - 1][y] < MAP[x][y])
            dp[x][y] = max(dp[x][y], dp[x - 1][y] + 1);
        if (MAP[x][y - 1] < MAP[x][y])
            dp[x][y] = max(dp[x][y], dp[x][y - 1] + 1);
        if (MAP[x + 1][y] < MAP[x][y])
            dp[x][y] = max(dp[x][y], dp[x + 1][y] + 1);
        if (MAP[x][y + 1] < MAP[x][y])
            dp[x][y] = max(dp[x][y], dp[x][y + 1] + 1);
    }
    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
