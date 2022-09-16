#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > tree;

int dp[1501][2];
int vis[1501];

int dfs(int x) {
    vis[x] = 1;
    dp[x][1] = 1;
    dp[x][0] = 0;
    for (int i = 0; i < tree[x].size(); i++) {
        int y = tree[x][i];
        if (vis[y] == 1) continue;
        dfs(y);
        dp[x][0] += dp[y][1];
        dp[x][1] += min(dp[y][1], dp[y][0]);
    }
    return min(dp[x][0], dp[x][1]);
}

int main() {
    int tmp = -1;
    memset(vis, 0, sizeof(vis));
    memset(dp, 0, sizeof(dp));
    int n;
    cin >> n;
    tree.resize(n);
    for (int i = 0; i < n; i++) {
        int k, m;
        cin >> k >> m;
        if (tmp < 0) tmp = k;
        for (int j = 0; j < m; j++) {
            int tt;
            cin >> tt;
            tree[k].push_back(tt);
            tree[tt].push_back(k);
        }
    }
    int ans = dfs(tmp);
    cout << ans << endl;
    return 0;
}