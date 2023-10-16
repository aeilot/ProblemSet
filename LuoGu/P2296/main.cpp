#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define INF 999999999
struct Node {
    int to, next;
    bool exist;
} NDS[400002];

int head[10001];
int cnt = 0;
// bool exi[10001][10001];
void add(int u, int v, bool exist) {
    if (u == v) return;  // Remove Self-Loop
    //    if(exi[u][v] && exist) return; // Remove Duplicates
    //    exi[u][v] = true;
    NDS[cnt].to = v;
    NDS[cnt].next = head[u];
    NDS[cnt].exist = exist;
    head[u] = cnt++;
}

int s, t;
bool vis[10001];
bool valid[10001];
bool val[10001];

void pre(int x) {
    val[x] = true;
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y] || NDS[i].exist) continue;
        pre(y);
    }
}

void pre2(int x) {
    bool flag = val[x];
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y] || !NDS[i].exist) continue;
        if (!val[y]) {
            flag = false;
            continue;
        }
        pre2(y);
    }
    valid[x] = flag;
}
int n, m;
int dis[10001];
void dfs(int x) {
    priority_queue<pair<int, int> > pq;
    for (int i = 0; i <= n; i++) {
        dis[i] = INF;
    }
    dis[x] = 0;
    pq.push(make_pair(dis[x], x));
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        for (int i = head[cur]; i != -1; i = NDS[i].next) {
            int y = NDS[i].to;
            if (!NDS[i].exist || !valid[y]) continue;
            if (dis[y] > dis[cur] + 1) {
                dis[y] = dis[cur] + 1;
                pq.push(make_pair(dis[y], y));
            }
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    std::ios::sync_with_stdio(0);
    // Type your code here
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y, true);
        add(y, x, false);
    }
    cin >> s >> t;
    pre(t);
    memset(vis, 0, sizeof(vis));
    pre2(s);
    //    for(int i = 1; i<=n; i++){
    //        cout << i << ' ' << valid[i] << endl;
    //    }
    memset(vis, 0, sizeof(vis));
    dfs(s);
    cout << (dis[t] != INF ? dis[t] : -1) << endl;
    return 0;
}
