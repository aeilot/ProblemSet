#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int to, next, w;
} NDS[50100];

int cnt = 0;
int head[50100];

void add(int x, int y, int w) {
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    NDS[cnt].w = w;
    head[x] = cnt++;
}

int n, m;
int dis[50100];
bool vis[50100];
int ccnt[50100];
bool spfa(int x) {
    for (int i = 0; i <= n; i++) {
        dis[i] = 0x3f3f3f3f;
    }
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    vis[0] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        vis[t] = 0;
        for (int i = head[t]; i != -1; i = NDS[i].next) {
            int y = NDS[i].to;
            if (dis[y] > dis[t] + NDS[i].w) {
                dis[y] = dis[t] + NDS[i].w;
                if (!vis[y]) {
                    vis[y] = 1;
                    q.push(y);
                    ccnt[y]++;
                    if (ccnt[y] == n + 1) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        add(0, i, 0);
    }
    for (int i = 1; i <= m; i++) {
        int c, cc, y;
        cin >> c >> cc >> y;
        add(cc, c, y);
    }
    bool ans = spfa(0);
    if (!ans) {
        cout << "NO" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << dis[i] << " ";
        }
        cout << endl;
    }
    return 0;
}