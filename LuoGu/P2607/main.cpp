#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Node {
    long long next, to;
} NDS[2000010];

long long head[1000010];
long long fa[1000010];  // 一一对应 便于找环
bool vis[1000010];
long long W[1000010];
long long cnt = 0;
void add(long long u, long long v) {
    NDS[cnt].to = v;
    NDS[cnt].next = head[u];
    head[u] = cnt++;
}

long long DP[1000010][2];

long long ans = 0;
long long lst, cur;
long long rt;
bool visd[1000010];
void dfs(long long x) {
    visd[x] = 1;
    while (!visd[fa[x]]) {
        x = fa[x];
        visd[x] = 1;
    }
    lst = x;
    cur = fa[x];
}

void dp(long long x) {
    vis[x] = 1;
    DP[x][1] = W[x];
    DP[x][0] = 0;
    for (long long i = head[x]; i != -1; i = NDS[i].next) {
        long long y = NDS[i].to;
        if (y == rt) {
            DP[y][1] = LLONG_MIN;
            continue;
        }
        dp(y);
        DP[x][0] += max(DP[y][1], DP[y][0]);
        DP[x][1] += DP[y][0];
    }
}

void find_circle(long long x) {
    memset(visd, 0, sizeof(visd));
    dfs(x);
    rt = cur;
    dp(cur);
    long long t = max(DP[rt][0], DP[rt][1]);
    rt = lst;
    dp(lst);
    t = max(t, max(DP[rt][0], DP[rt][1]));
    ans += t;
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        long long w, h;
        cin >> w >> h;
        add(h, i);
        W[i] = w;
        fa[i] = h;
    }
    for (long long i = 1; i <= n; i++) {
        if (!vis[i]) {
            find_circle(i);
        }
    }
    cout << ans << endl;
    return 0;
}