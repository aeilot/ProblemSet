#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define MOD 100003

struct Node {
    int to, next;
} NDS[4000010];

int cnt = 0;
int head[1000010], vis[1000010], dis[1000010];
int ANS[1000010];

void add(int x, int y) {
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    head[x] = cnt++;
}

struct pos {
    int x, d;
    const bool operator<(const pos &a) const { return a.d < this->d; }
};

int n, m;

void dijkstra(int s) {
    for (int i = 0; i <= n; i++) {
        dis[i] = 0x3f3f3f3f;
    }
    priority_queue<pos> q;
    dis[s] = 0;
    vis[s] = 1;
    ANS[s] = 1;
    q.push({s, 0});
    while (!q.empty()) {
        pos now = q.top();
        q.pop();
        vis[now.x] = 0;
        for (int i = head[now.x]; i != -1; i = NDS[i].next) {
            int y = NDS[i].to;
            int x = now.x;
            if (dis[y] > dis[x] + 1) {
                dis[y] = dis[x] + 1;
                ANS[y] = ANS[x];
                if (!vis[y]) {
                    q.push({y, dis[y]});
                    vis[y] = 1;
                }
            } else if (dis[y] == dis[x] + 1) {
                ANS[y] += ANS[x];
                ANS[y] %= MOD;
            }
        }
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        cout << ANS[i] << endl;
    }
    return 0;
}