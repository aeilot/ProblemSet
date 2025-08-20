#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Node {
    int to, next;
} NDS[200010];

int head[100010], vis[100010];
int cnt = 0;
int W[100010];

void add(int u, int v) {
    NDS[cnt].to = v;
    NDS[cnt].next = head[u];
    head[u] = cnt++;
}

long long f[100010][21];
long long dep[100010];
int n, k;

void pre(int x) {
    vis[x] = 1;
    f[x][0] = W[x];
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        dep[y] = dep[x] + 1;
        pre(y);
        for (int j = 1; j <= k; j++) {
            f[x][j] += f[y][j - 1];
        }
    }
}

void dfs(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        if (dep[y] > dep[x]) {
            for (int j = k; j >= 2; j--) {
                f[y][j] -= f[y][j - 2];// 容斥原理
            }
            for (int j = 1; j <= k; j++) {
                f[y][j] += f[x][j - 1];
            }
            dfs(y);
        }
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        W[i] = c;
    }
    pre(1);
    memset(vis, 0, sizeof(vis));
    dfs(1);
    for (int i = 1; i <= n; i++) {
        long long ans = 0;
        for (int j = 0; j <= k; j++) {
            ans += f[i][j];
        }
        cout << ans << endl;
    }
    return 0;
}