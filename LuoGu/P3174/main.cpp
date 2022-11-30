#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
struct Node {
    int to, next;
} NDS[600010];

int head[600010], vis[600010];
int cnt = 0;
long long deg[600010];

void add(int u, int v) {
    NDS[cnt].to = v;
    NDS[cnt].next = head[u];
    head[u] = cnt++;
    deg[v]++;
}

long long f[600010];
long long ans;

void dfs(int x) {
    vis[x] = 1;
    long long max0 = 0, max1 = 0;
    int cnt = 0;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        cnt++;
        dfs(y);
        if (f[y] > max0) {
            max1 = max0;
            max0 = f[y];
        } else if (f[y] > max1) {
            max1 = f[y];
        }
    }
    /*
     * 分类讨论，记录最大次大
     * 特判 单个点？链？
     */
    f[x] = (deg[x] == 1) ? 1 : max0 + deg[x] + ((x == 1) ? 0 : -1);
    if (cnt == 0)
        ans = deg[x] + 1;  // 没有 max0,max1
    else if (cnt == 1) {
        ans = max(ans, max0 + deg[x]);
    } else {
        ans = max(ans, max1 + max0 + deg[x] - 1);
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}