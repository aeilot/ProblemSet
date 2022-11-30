#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Node {
    int next;
    int to;
} NDS[2000010];

int head[1000010];
long long DEP[1000010];
long long size[1000010];
long long F[1000010];
long long G[1000010];
long long deg[1000010];
int cnt = 0;

void add(int x, int y) {
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    head[x] = cnt++;
    deg[x]++;
}

int vis[1000010];

void PRE(int x) {
    vis[x] = 1;
    size[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        DEP[y] = DEP[x] + 1;
        PRE(y);
        size[x] += size[y];
    }
}

int n;

void DFS1(int x) {
    vis[x] = 1;
    F[x] = DEP[x];
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        DFS1(y);
        F[x] += F[y];
    }
}

void DFS2(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        G[y] = G[x] + n - 2 * size[y];
        DFS2(y);
    }
}

int main() {
    // Type your code here
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    PRE(1);
    memset(vis, 0, sizeof(vis));
    DFS1(1);
    G[1] = F[1];
    memset(vis, 0, sizeof(vis));
    DFS2(1);
    long long ans = 0;
    int mm = -1;
    for (int i = 1; i <= n; i++) {
        if (G[i] > ans) {
            ans = G[i];
            mm = i;
        }
    }
    cout << mm << endl;
    return 0;
}