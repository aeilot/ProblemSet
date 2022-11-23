#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int to, next;
} NDS[200010];

int P[100010];
int fa[100010];
int head[100010], vis[100010];
int cnt = 0;

void add(int u, int v) {
    NDS[cnt].next = head[u];
    NDS[cnt].to = v;
    head[u] = cnt++;
}

int find(int x) { return (x == fa[x]) ? x : fa[x] = find(fa[x]); }

double F[100010][2];

void dfs(int x) {
    vis[x] = 1;
    F[x][1] = P[x];
    F[x][0] = 0;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        dfs(y);
        F[x][0] += max(F[y][1], F[y][0]);
        F[x][1] += F[y][0];
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> P[i];
        fa[i] = i;
    }
    int S, T;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v)) {
            S = u;
            T = v;
            continue;
        }
        add(u, v);
        add(v, u);
        fa[find(v)] = find(u);
    }
    double k;
    cin >> k;
    double ans = 0;
    dfs(S);
    ans = F[S][0];
    memset(vis, 0, sizeof(vis));
    dfs(T);
    ans = max(ans, F[T][0]);
    double pf = ans * k;
    printf("%.1lf\n", pf);
    return 0;
}