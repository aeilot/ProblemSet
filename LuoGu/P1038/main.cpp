#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define ll long long

struct Edge {
    int to, next, from;
    ll w;
} NDS[101 * 101];
ll C[102], U[102];
ll indeg[102];
bool vis[102];
ll odeg[102];

int head[20001];
int cnt = 0;
void add(int u, int v, ll w) {
    NDS[cnt].to = v;
    NDS[cnt].w = w;
    NDS[cnt].from = u;
    NDS[cnt].next = head[u];
    head[u] = cnt++;
    indeg[v]++;
    odeg[u]++;
}

int main() {
    memset(head, -1, sizeof(head));
    std::ios::sync_with_stdio(0);
    // Type your code here
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> U[i];
    }
    for (int i = 0; i < p; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    queue<int> pq;
    queue<int> qq;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0 && C[i] > 0) {
            pq.push(i);
            vis[i] = 1;
        }
        if (indeg[i] != 0) {
            C[i] -= U[i];
        }
        if (odeg[i] == 0) qq.push(i);
    }
    while (!pq.empty()) {
        int x = pq.front();
        pq.pop();
        for (int i = head[x]; i != -1; i = NDS[i].next) {
            int y = NDS[i].to;
            indeg[y]--;
            if (C[x] > 0) C[y] += NDS[i].w * C[x];
        }
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0 && !vis[i] && C[i] > 0) {
                pq.push(i);
                vis[i] = 1;
            }
        }
    }
    bool flag = false;
    while (!qq.empty()) {
        int x = qq.front();
        qq.pop();
        if (C[x] > 0) {
            cout << x << " " << C[x] << endl;
            flag = true;
        }
    }
    if (!flag) {
        cout << "NULL" << endl;
    }
    cout << endl;
    return 0;
}
