#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int next, to, w;
} NDS[50010];

int cnt = 0, head[50010];
int n, m;

void add(int x, int y, int w) {
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    NDS[cnt].w = w;
    head[x] = cnt++;
}

int cc[50010];
long long dis[50010];
long long h[50010];
bool vis[50010];

bool spfa(int s) {
    for (int i = 0; i <= n; i++) {
        h[i] = 1e9;
    }
    queue<int> q;
    q.push(s);
    h[s] = 0;
    vis[s] = 1;
    cc[s]++;
    while (!q.empty()) {
        int tt = q.front();
        q.pop();
        vis[tt] = 0;
        for (int i = head[tt]; i != -1; i = NDS[i].next) {
            int y = NDS[i].to;
            if (h[y] > h[tt] + NDS[i].w) {
                h[y] = h[tt] + NDS[i].w;
                if (vis[y] == 0) {
                    q.push(y);
                    vis[y] = 1;
                    cc[y]++;
                    if (cc[y] == n + 1) return false;
                }
            }
        }
    }
    return true;
}

struct pos {
    int x;
    long long d;
    const bool operator<(const pos& p) const { return p.d < this->d; }
};

void dijkstra(int s) {
    for (int i = 0; i <= n; i++) {
        dis[i] = 1e9;
    }
    priority_queue<pos> q;
    dis[s] = 0;
    vis[s] = 1;
    q.push({s, 0});
    while (!q.empty()) {
        pos t = q.top();
        int tt = t.x;
        q.pop();
        vis[tt] = 0;
        for (int i = head[tt]; i != -1; i = NDS[i].next) {
            int y = NDS[i].to;
            if (dis[y] > dis[tt] + NDS[i].w) {
                dis[y] = dis[tt] + NDS[i].w;
                if (vis[y] == 0) {
                    q.push({y, dis[y]});
                    vis[y] = 1;
                }
            }
        }
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    for (int i = 1; i <= n; i++) add(0, i, 0);
    bool t = spfa(0);
    if (!t) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j != -1; j = NDS[j].next) {
            NDS[j].w += h[i] - h[NDS[j].to];
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        dijkstra(i);
        long long ans = 0;
        for (int j = 1; j <= n; j++) {
            if (dis[j] == 1e9) {
                ans += j * 1e9;
            } else {
                ans += j * (dis[j] + h[j] - h[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}