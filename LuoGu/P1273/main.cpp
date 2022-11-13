#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Nodes {
    int to, next, w;
} NDS[6010];

int P[3010];
int C[3010];
int dp[3010][3010];
int head[3010];
int cnt = 0;
int n, m;

void add(int a, int b, int w) {
    NDS[cnt].to = b;
    NDS[cnt].next = head[a];
    NDS[cnt].w = w;
    head[a] = cnt++;
}

int solve(int x) {
    dp[x][0] = 0;
    if (x >= 1 + n - m) {
        dp[x][1] = P[x];
        return 1;
    }
    int cc = 0;
    for (int i = head[x]; i; i = NDS[i].next) {
        int to = NDS[i].to, w = NDS[i].w;
        int t = solve(to);
        cc += t;
        for (int j = cc; j > 0; j--) {
            for (int z = 1; z <= t; z++) {
                if (j - z >= 0)
                    dp[x][j] = max(dp[x][j], dp[x][j - z] + dp[to][z] - w);
            }
        }
    }
    return cc;
}

int main() {
    // Type your code here
    memset(dp, ~0x3f, sizeof(dp));
    memset(dp, 0, sizeof(dp[0]));
    cin >> n >> m;
    for (int i = 1; i <= n - m; i++) {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, c;
            cin >> a >> c;
            add(i, a, c);
        }
    }
    for (int i = 1; i <= m; i++) {
        int a;
        cin >> a;
        P[i + n - m] = a;
    }
    solve(1);
    for (int i = m; i >= 1; i--) {
        if (dp[1][i] >= 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}