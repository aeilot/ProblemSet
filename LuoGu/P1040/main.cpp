#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long dp[31][31];
int root[31][31];
int sc[31];

void print(int i, int j) {
    if (i > j || i < 1 || j < 1) return;
    if (i == j) {
        cout << i << " ";
        return;
    }
    cout << root[i][j] << " ";
    print(i, root[i][j] - 1);
    print(root[i][j] + 1, j);
}

long long dfs(int i, int j) {
    if (i < 1 || j < 1) return 0;
    if (i > j) return 1;
    if (i == j) return sc[i];
    if (dp[i][j] != 0) return dp[i][j];
    long long ans = 0;
    int tt = 0;
    for (int x = i; x <= j; x++) {
        long long tmp = sc[x] + dfs(i, x - 1) * dfs(x + 1, j);
        if (tmp > ans) {
            ans = tmp;
            tt = x;
        }
    }
    root[i][j] = tt;
    return dp[i][j] = ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> sc[i];
    }
    memset(dp, 0, sizeof(dp));
    memset(root, -1, sizeof(root));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = sc[i];
    }
    dfs(1, n);
    cout << dp[1][n] << endl;
    print(1, n);
    return 0;
}