#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Node {
    int to, next, w;
} NDS[200010];

int C[100010];
int head[100010];
int cnt = 0;

void add(int a, int b, int w) {
    NDS[cnt].to = b;
    NDS[cnt].next = head[a];
    NDS[cnt].w = w;
    head[a] = cnt++;
}

int vis[100010];
long long f[100010];
long long size[100010];

void pre(int x) {
    vis[x] = 1;
    size[x] = C[x];
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to, l = NDS[i].w;
        if (vis[y]) continue;
        pre(y);
        size[x] += size[y];
    }
}

void dfs1(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to, l = NDS[i].w;
        if (vis[y]) continue;
        dfs1(y);
        f[x] += l * size[y] + f[y];
    }
}

long long g[100010];
int N;
long long CNT = 0;

void dfs2(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to, l = NDS[i].w;
        if (vis[y]) continue;
        g[y] = g[x] - l * size[y] + (CNT - size[y]) * l;
        dfs2(y);
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
        CNT += C[i];
    }
    for (int i = 1; i <= N - 1; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        add(a, b, l);
        add(b, a, l);
    }
    pre(1);
    memset(vis, 0, sizeof(vis));
    dfs1(1);
    memset(vis, 0, sizeof(vis));
    g[1] = f[1];
    dfs2(1);
    long long ans = LLONG_MAX;
    for (int i = 1; i <= N; i++) {
        ans = min(ans, g[i]);
    }
    cout << ans << endl;
    return 0;
}