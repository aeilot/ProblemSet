#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int k;

int st[500001][19];
int vis[500001];
int d[500001];
int lg[500001];

int head[2 * 500001];
struct edge {
    int from, to, next;
} ed[2 * 500001];
int cnt = 0;

void addNode(int from, int to) {
    ed[cnt].from = from;
    ed[cnt].to = to;
    ed[cnt].next = head[from];
    head[from] = cnt++;
}

void dfs(int x, int fa) {
    vis[x] = 1;
    if (fa != -1)
        d[x] = d[fa] + 1;
    else
        d[x] = 0;
    if (d[x] != 0)
        st[x][0] = fa;
    else
        st[x][0] = x;
    for (int i = 1; (1 << i) <= d[x]; i++) {
        st[x][i] = st[st[x][i - 1]][i - 1];
    }
    for (int i = head[x]; i != -1; i = ed[i].next) {
        int y = ed[i].to;
        if (vis[y] == 1) continue;
        dfs(y, x);
    }
}

int log2(int n) { return lg[n]; }

int lca(int a, int b) {
    if (d[a] > d[b]) swap(a, b);
    for (int i = log2(d[b] - d[a]); i >= 0; i--) {
        if (d[st[b][i]] >= d[a]) b = st[b][i];
    }

    if (a == b) {
        return a;
    }

    for (int i = log2(d[a]); i >= 0; i--) {
        if (st[a][i] != st[b][i]) {
            a = st[a][i];
            b = st[b][i];
        }
    }
    return st[a][0];
}

void solve(int a, int b, int c) {
    int l1 = lca(a, b);
    int l2 = lca(c, b);
    int l3 = lca(a, c);
    long long ans;
    int t;
    if (l1 == l2) {
        t = l3;
    } else if (l2 == l3) {
        t = l1;
    } else if (l1 == l3) {
        t = l2;
    }
    ans = d[a] + d[b] + d[c] - d[l1] - d[l2] - d[l3];
    cout << t + 1 << " " << ans << endl;
}

int main() {
    memset(vis, 0, sizeof(vis));
    memset(st, 0, sizeof(st));
    memset(d, 0, sizeof(d));
    memset(head, -1, sizeof(head));
    int n, m;
    cin >> n >> m;
    k = log(n) / log(2);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        addNode(a, b);
        addNode(b, a);
    }
    dfs(0, -1);
    for (int i = 1; i < n; i++) {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        solve(a, b, c);
    }
    return 0;
}