#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int W[10010];
long long W2[10010];
int in[10010];

struct Node {
    int from, next, to;
} NDS[100010], NDS2[100010];

int cnt = 0;
int cnt2 = 0;
int head[10010], head2[10010];

void add(int x, int y) {
    NDS[cnt].from = x;
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    head[x] = cnt++;
}

void add2(int x, int y) {
    NDS2[cnt2].to = y;
    NDS2[cnt2].next = head2[x];
    head2[x] = cnt2++;
    in[y]++;
}

int dfn[10010], low[10010];
int cc = 0;
bool vis[10010];
int id[10010];
int idc = 0;
stack<int> qq;
void tarjan(int x) {
    dfn[x] = low[x] = ++cc;
    qq.push(x);
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (vis[y]) {
            low[x] = min(dfn[y], low[x]);
        }
    }
    if (dfn[x] == low[x]) {
        idc++;
        int now;
        do {
            now = qq.top();
            id[now] = idc;
            W2[idc] += W[now];
            vis[now] = 0;
            qq.pop();
        } while (now != x);
    }
}

struct topp {
    int x, in;
    const bool operator<(const topp &a) const { return a.in < this->in; }
};

int n, m;
long long dp[100010];
long long ans = 0;
vector<int> seq;
void topo() {
    priority_queue<topp> pq;
    for (int i = 1; i <= idc; i++) {
        dp[i] = W2[i];
        if (in[i] == 0) pq.push({i, in[i]});
    }
    while (!pq.empty()) {
        int now = pq.top().x;
        seq.push_back(now);
        ans = max(ans, dp[now]);
        pq.pop();
        for (int i = head2[now]; i != -1; i = NDS2[i].next) {
            int y = NDS2[i].to;
            in[y]--;
            dp[y] = max(dp[y], dp[now] + W2[y]);
            if (in[y] == 0) pq.push({y, in[y]});
        }
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    memset(head2, -1, sizeof(head2));
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> W[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (id[NDS[i].from] != id[NDS[i].to]) {
            add2(id[NDS[i].from], id[NDS[i].to]);
        }
    }
    topo();
    cout << ans << endl;
    return 0;
}