#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX_LOG 23

struct Tr {
    int from, to, next;
} ed[400001];
int head[400001];
int vis[400001];
int d[200001];
int val[200001];
int fa[200001];
int st[200001][24];
int cnt = 0;

void build(int a, int b) {
    ed[cnt].from = a;
    ed[cnt].to = b;
    ed[cnt].next = head[a];
    head[a] = cnt++;
}

int log2(int a) { return log(a) / log(2); }

void dfs(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = ed[i].next) {
        int y = ed[i].to;
        if (vis[y] == 1) continue;
        d[y] = d[x] + 1;
        fa[y] = x;
        st[y][0] = x;
        for (int j = 1; j <= MAX_LOG; j++) {
            st[y][j] = st[st[y][j - 1]][j - 1];
        }
        dfs(y);
    }
}

void refresh(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = ed[i].next) {
        int y = ed[i].to;
        if (vis[y] == 1) continue;
        dfs(y);
        val[x] += val[y];
    }
}

int lca(int a, int b) {
    if (d[a] > d[b]) swap(a, b);
    for (int i = MAX_LOG; i >= 0; i--) {
        if (d[st[b][i]] >= d[a]) b = st[b][i];
    }
    if (a == b) {
        return a;
    }
    for (int i = MAX_LOG; i >= 0; i--) {
        if (st[a][i] != st[b][i]) {
            a = st[a][i];
            b = st[b][i];
        }
    }
    return st[a][0];
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    memset(val, 0, sizeof(val));
    memset(d, 0, sizeof(d));
    memset(fa, -1, sizeof(fa));
    memset(vis, 0, sizeof(vis));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        build(u, v);
        build(v, u);
    }
    dfs(0);
    fa[0] = -1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        val[u]++;
        val[v]++;
        val[lca(u, v)] -= 2;
    }
    memset(vis, 0, sizeof(vis));
    refresh(0);
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (val[i] == 0) ans += m;
        if (val[i] == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}