#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 5010 * 2;

int cnt = -1;
int head[MAXN], nxt[MAXN], to[MAXN];

void add(int u, int v) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

bool vis[MAXN];
bool ans = false;

void dfs(int u) {
    vis[u] = true;
    for (int i = head[u]; i != -1; i = nxt[i]) {
        if (vis[i]) {
            ans = true;
            return;
        }
        dfs(i);
    }
}

int main(int argc, char *argv[]) {
    std::fill(nxt, nxt + MAXN, -1);
    std::fill(vis, vis + MAXN, 0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int f;
        cin >> f;
        // add(i+1, f);
        to[i] = f;
    }
    for (int i = 1; i <= n; i++) {
        if (to[to[to[i]]] == i) ans = true;
    }
    // dfs(1);
    cout << (ans == true ? "YES" : "NO") << endl;
    return 0;
}
