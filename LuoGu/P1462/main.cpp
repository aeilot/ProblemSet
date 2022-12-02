// 图论 + 二分
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int to, next, C;
} NDS[100010];

int cnt = 0;
int F[10010];
int head[10010];

void add(int x, int y, int c) {
    NDS[cnt].to = y;
    NDS[cnt].C = c;
    NDS[cnt].next = head[x];
    head[x] = cnt++;
}
int n, m, b;

long long dis[10010];
bool vis[10010];

struct pos {
    int x;
    long long d;
    const bool operator<(const pos &a) const { return a.d < this->d; }
};

bool check(long long s) {
    for (int i = 1; i <= n; i++) {
        dis[i] = 1e18;
    }
    memset(vis, 0, sizeof(vis));
    priority_queue<pos> q;
    vis[1] = 1;
    dis[1] = 0;
    q.push({1, 0});
    while (!q.empty()) {
        pos now = q.top();
        int x = now.x;
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i != -1; i = NDS[i].next) {
            int y = NDS[i].to;
            if (dis[y] > dis[x] + NDS[i].C && F[y] <= s) {
                dis[y] = dis[x] + NDS[i].C;
                if (!vis[y]) {
                    q.push({y, dis[y]});
                    vis[y] = 1;
                }
            }
        }
    }
    if (dis[n] > b) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    cin >> n >> m >> b;
    long long r = 0, l = 0;
    for (int i = 1; i <= n; i++) {
        cin >> F[i];
        r = max(r, (long long)F[i]);
    }
    l = min(F[1], F[n]);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    if (check(1e9 + 1)) {  // 可行特判
        cout << "AFK" << endl;
        return 0;
    }
    long long mid = (l + r) / 2;
    while (l <= r) {
        mid = (l + r) / 2;
        if (mid < F[1] || check(mid)) {  // 起点特判
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}