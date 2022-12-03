#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int from, to, next;
    long long w;

    const bool operator<(const Node& a) const { return a.w > this->w; }
} NDS[100010], TRE[100010];

int cnt = 0, cntr = 0;
int head[10010], hetr[10010];
int fa[10010];
int LG[10010];

void add(int x, int y, long long w) {
    NDS[cnt].from = x;
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    NDS[cnt].w = w;
    head[x] = cnt++;
}

int fd(int x) { return (x == fa[x]) ? x : fa[x] = fd(fa[x]); }

void kruskal() {
    priority_queue<Node> ndsq;
    for (int i = 0; i < cnt; i++) {
        ndsq.push(NDS[i]);
    }
    while (!ndsq.empty()) {
        Node now = ndsq.top();
        ndsq.pop();
        if (fd(now.from) == fd(now.to)) {
            continue;
        }
        fa[fd(now.from)] = fd(now.to);
        TRE[cntr].from = now.from;
        TRE[cntr].to = now.to;
        TRE[cntr].next = hetr[now.from];
        TRE[cntr].w = now.w;
        hetr[now.from] = cntr++;
        TRE[cntr].from = now.to;
        TRE[cntr].to = now.from;
        TRE[cntr].next = hetr[now.to];
        TRE[cntr].w = now.w;
        hetr[now.to] = cntr++;
    }
}

bool vis[10010];
int ST[10010][22];
long long mm[10010][22];
long long dep[10010];

void pre(int x) {
    vis[x] = 1;
    for (int i = 1; i <= 20; i++) {
        ST[x][i] = ST[ST[x][i - 1]][i - 1];
        mm[x][i] = min(mm[x][i - 1], mm[ST[x][i - 1]][i - 1]);
    }
    for (int i = hetr[x]; i != -1; i = TRE[i].next) {
        int y = TRE[i].to;
        if (vis[y]) continue;
        dep[y] = dep[x] + 1;
        ST[y][0] = x;
        mm[y][0] = TRE[i].w;
        pre(y);
    }
}

long long lca(int a, int b) {
    if (fd(a) != fd(b)) return -1;
    long long ans = 1e9;
    if (dep[a] > dep[b]) swap(a, b);
    while (dep[b] > dep[a]) {
        ans = min(ans, mm[b][LG[dep[b] - dep[a]]]);
        b = ST[b][LG[dep[b] - dep[a]]];
    }
    if (a == b) {
        return ans;
    }
    for (int i = 20; i >= 0; i--) {
        if (ST[a][i] != ST[b][i]) {
            ans = min(ans, min(mm[a][i], mm[b][i]));
            a = ST[a][i];
            b = ST[b][i];
        }
    }
    return min(ans, min(mm[a][0], mm[b][0]));
}

int main() {
    // Type your code here
    LG[2] = 1;
    for (int i = 3; i <= 10001; i++) {
        LG[i] = LG[i / 2] + 1;
    }
    memset(head, -1, sizeof(head));
    memset(hetr, -1, sizeof(hetr));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y;
        long long z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    memset(vis, 0, sizeof(vis));
    kruskal();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 20; j++) {
            mm[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            pre(i);
            mm[i][0] = 0;
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}