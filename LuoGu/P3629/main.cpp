#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Edge {
    int from, to, next, w;
} ed[200001];
int head[100001];
int cnt = 0;
int vis[100001];

void add(int x, int y) {
    ed[cnt].from = x;
    ed[cnt].to = y;
    ed[cnt].next = head[x];
    ed[cnt].w = 1;
    head[x] = cnt++;
}

int ans = -100;
int d[100001];
void dfs(int x) {
    vis[x] = 1;
    for (int i = head[x]; i >= 0; i = ed[i].next) {
        int y = ed[i].to;
        if (vis[y] == 1) continue;
        dfs(y);
        ans = max(ans, d[x] + d[y] + ed[i].w);
        d[x] = max(d[x], d[y] + ed[i].w);
    }
}

int c = 0;
int g[100001];

void dfs1(int x, bool rec) {
    vis[x] = 1;
    for (int i = head[x]; i >= 0; i = ed[i].next) {
        int y = ed[i].to;
        if (vis[y] == 1) continue;
        d[y] = d[x] + 1;
        if (rec) g[y] = x;
        if (d[y] > d[c]) {
            c = y;
        }
        dfs1(y, rec);
    }
}

void change(int a) {
    while (g[a] >= 0) {
        int fa = g[a];
        for (int i = head[fa]; i >= 0; i = ed[i].next) {
            if (ed[i].to == a) {
                ed[i].w = -1;
                break;
            }
        }
        for (int i = head[a]; i >= 0; i = ed[i].next) {
            if (ed[i].to == fa) {
                ed[i].w = -1;
                break;
            }
        }
        a = fa;
    }
}

int main() {
    memset(head, -1, sizeof(head));
    memset(d, 0, sizeof(d));
    memset(g, -1, sizeof(g));
    memset(vis, 0, sizeof(vis));
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        add(a, b);
        add(b, a);
    }
    n = (n - 1) * 2;
    int aa = n;
    dfs1(0, false);
    memset(d, 0, sizeof(d));
    memset(vis, 0, sizeof(vis));
    dfs1(c, true);
    aa = aa - d[c] + 1;
    if (k == 1) {
        cout << aa << endl;
    } else {
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        ans = -100;
        change(c);
        dfs(0);
        aa = aa - ans + 1;
        cout << aa << endl;
    }
    return 0;
}