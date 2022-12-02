#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int from, next, to, w;
    const bool operator<(const Node &x) const { return x.w < this->w; }
} NDS[200010];

int head[5010], cnt = 0;

void add(int x, int y, int w) {
    NDS[cnt].from = x;
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    NDS[cnt].w = w;
    head[x] = cnt++;
}

int fa[5010];
long long ans = 0;

int find(int x) { return (x == fa[x]) ? x : fa[x] = find(fa[x]); }

bool vis[5010];
int n, m;

void kruskal() {
    priority_queue<Node> pq;
    for (int i = 0; i < cnt; i++) {
        pq.push((NDS[i]));
    }
    while (!pq.empty()) {
        Node x = pq.top();
        pq.pop();
        if (find(x.from) == find(x.to)) {
            continue;
        }
        vis[x.from] = vis[x.to] = 1;
        ans += x.w;
        fa[find(x.from)] = find(x.to);
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }
    kruskal();
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            cout << "orz" << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}