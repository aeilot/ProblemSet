#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Node {
    int to, next;
} G[4010];

int head[5010], vis[4010], W[4010];
int cnt = 0;

void add(int x, int y, int w) {
    G[cnt].to = y;
    G[cnt].next = head[x];
    W[cnt] = w;
    head[x] = cnt++;
}

int n, k;
long long size[4010][2];

// void pre(int x){
//     vis[x] = 1;
//     size[x]  =1;
//     for(int i = head[x]; i !=-1; i = G[i].next){
//         int y = G[i].to;
//         if(vis[y]) continue;
//         pre(y);
//         size[x] += size[y];
//     }
// }

long long f[4010][2];

void dfs(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = G[i].next) {
        int y = G[i].to;
        if (vis[y]) continue;
        dfs(y);
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(0);
    cout << max(f[0][0], f[0][1]) << endl;
    return 0;
}