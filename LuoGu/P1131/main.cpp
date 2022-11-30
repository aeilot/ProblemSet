#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

struct Node {
    int to, next;
} NDS[1000010];

int head[500010], vis[500010];
int T[1000010];
int cnt = 0;

void add(int u, int v, int t) {
    NDS[cnt].to = v;
    NDS[cnt].next = head[u];
    T[cnt] = t;
    head[u] = cnt++;
}

long long F[500010], size[500010], ANS[500010];
long long G[500010];
bool lf[500010];

void dfs(int x) {
    vis[x] = 1;
    bool leaf = true;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        leaf = false;
        F[y] = F[x] + T[i];
        dfs(y);
        G[x] = max(G[x], G[y]);
        size[x] += size[y];
    }
    if (leaf == true) {
        size[x] = 1;
        G[x] = F[x];
        lf[x] = true;
    }
    //    cout << x << " " << size[x] << " " << G[x] << " " << F[x] << endl;
}

void dfs2(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        dfs2(y);
        ANS[x] += ANS[y] + G[x] - G[y];
    }
    //    cout << x << " " << ANS[x] << endl;
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    int N;
    cin >> N;
    int root;
    cin >> root;
    for (int i = 1; i <= N - 1; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        add(a, b, t);
        add(b, a, t);
    }
    dfs(root);
    memset(vis, 0, sizeof(vis));
    dfs2(root);
    cout << ANS[root] << endl;
    return 0;
}