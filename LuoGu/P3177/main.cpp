#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Node {
    long long to, next;
} G[4010];

long long head[4010], vis[4010];
long long W[4010];
long long cnt = 0;

void add(long long x, long long y, long long w) {
    G[cnt].to = y;
    G[cnt].next = head[x];
    W[cnt] = w;
    head[x] = cnt++;
}

long long n, k;
long long size[4010];

void pre(long long x) {
    vis[x] = 1;
    size[x] = 1;
    for (long long i = head[x]; i != -1; i = G[i].next) {
        long long y = G[i].to;
        if (vis[y]) continue;
        pre(y);
        size[x] += size[y];
    }
}

long long f[4010][4010];

void dfs(long long x) {
    vis[x] = 1;
    f[x][0] = f[x][1] = 0;
    for (long long i = head[x]; i != -1; i = G[i].next) {
        long long y = G[i].to;
        if (vis[y]) continue;
        dfs(y);
        for (long long l = min(k, size[x]); l >= 0; l--) {
            for (long long s = 0; s <= min(l, size[y]); s++) {
                if (f[x][l - s] == -1) continue;
                f[x][l] = max(f[x][l],
                              f[x][l - s] + f[y][s] + s * (k - s) * W[i] +
                                      (size[y] - s) * (n - k - size[y] + s) * W[i]);
            }
        }
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    cin >> n >> k;
    for (long long i = 0; i < n - 1; i++) {
        long long u, v;
        long long w;
        cin >> u >> v >> w;
        u--;
        v--;
        add(u, v, w);
        add(v, u, w);
    }
    pre(0);
    memset(vis, 0, sizeof(vis));
    memset(f, -1, sizeof(f));
    dfs(0);
    cout << f[0][k] << endl;
    return 0;
}