#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long dp[6001][15];
int vis[6001];
int ha[6001];
vector<vector<int>> tr;

int dfs(int x) {
    vis[x] = 1;
    dp[x][0] = 0;
    dp[x][1] = ha[x];
    for (int i = 0; i < tr[x].size(); i++) {
        int y = tr[x][i];
        if (vis[y] == 1) continue;
        dfs(y);
        dp[x][1] += dp[y][0];
        dp[x][0] += max(dp[y][0], dp[y][1]);
    }
    return max(dp[x][0], dp[x][1]);
}

int main() {
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    int n;
    cin >> n;
    tr.resize(n);
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        ha[i] = r;
    }
    for (int i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        t1--;
        t2--;
        tr[t1].push_back(t2);
        tr[t2].push_back(t1);
        vis[t1] = -1;
    }
    int root;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            vis[i] = -1;
            root = i;
            break;
        }
    }
    int ans = dfs(root);
    cout << ans << endl;
    return 0;
}