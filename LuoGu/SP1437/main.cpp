#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int cnt = -1;

constexpr int MAX_N = 10000 * 2 + 5;

int head[MAX_N], nxt[MAX_N], to[MAX_N];
void add(int u, int v) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

int deepest_u = -1;
int depth_max = -1;
int depth = 0;
bool vis[MAX_N];
void dfs(int u) {
    vis[u] = true;
    if (depth > depth_max) {
        depth_max = depth;
        deepest_u = u;
    }
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int y = to[i];
        if (vis[y]) continue;
        depth += 1;
        dfs(y);
        depth -= 1;
    }
}

int s, t;
int len = 0;
void find_path(int u) {
    vis[u] = true;
    if (u == t) {
        cout << len << endl;
        return;
    }
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int y = to[i];
        if (vis[y]) continue;
        len += 1;
        dfs(y);
        len -= 1;
    }
}

int main(int argc, char *argv[]) {
    std::fill(head, head + MAX_N, -1);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    std::fill(vis, vis + MAX_N, false);
    dfs(1);
    s = deepest_u;
    depth_max = -1;
    depth = 0;
    deepest_u = -1;
    std::fill(vis, vis + MAX_N, false);
    dfs(s);
    t = deepest_u;
    cout << depth_max << endl;
    return 0;
}
