#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int next, to;
    long long w;
} NDS[200010];

int head[200010], cnt = 0;
int dis[100010];

void add(int x, int y, int w) {
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    NDS[cnt].w = w;
    head[x] = cnt++;
}

struct pos {
    int x, d;
    const bool operator<(const pos &a) const {
        return a.d < this->d;
    }
};

bool vis[100010];

void dij(int s) {
    dis[s] = 0;
    priority_queue<pos> q;
    vis[s] = 1;
    q.push({s, 0});
    while (!q.empty()) {
        pos tmp = q.top();
        q.pop();
        int x = tmp.x;
        vis[x] = 0;
        for (int i = head[x]; i != -1; i = NDS[i].next) {
            int y = NDS[i].to;
            if (dis[y] > dis[x] + NDS[i].w) {
                dis[y] = dis[x] + NDS[i].w;
                if (!vis[y]) {
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
    memset(dis, 0x3f, sizeof(dis));
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dij(s);
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << endl;
    return 0;
}