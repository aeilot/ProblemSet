#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
#define ll long long

int k;
int n, m;

struct Node {
    int to, next;
} NDS[40002];
int head[2502];
int cnt = 0;
ll C[2502];
void add(int u, int v) {
    NDS[cnt].to = v;
    NDS[cnt].next = head[u];
    head[u] = cnt++;
}

int dis[2502];
bool ok[2502][2502];
vector<int> f[2502];

void bfs(int x) {
    memset(dis, -1, sizeof(dis));
    queue<int> bq;
    bq.push(x);
    dis[x] = 0;
    while (!bq.empty()) {
        int t = bq.front();
        bq.pop();
        if (t != x) {
            ok[x][t] = true;
            if (x != 1 && ok[1][t]) {
                f[x].push_back(t);
                sort(f[x].begin(), f[x].end(),
                     [](int u, int v) { return C[u] > C[v]; });// TODO: ?
                if (f[x].size() > 3) f[x].pop_back();
            }
        }

        if (dis[t] == k + 1) continue;
        for (int i = head[t]; i != -1; i = NDS[i].next) {
            int y = NDS[i].to;
            if (dis[y] == -1) {
                dis[y] = dis[t] + 1;
                bq.push(y);
            }
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    std::ios::sync_with_stdio(0);
    // Type your code here
    cin >> n >> m >> k;
    ok[1][1] = false;
    for (int i = 2; i <= n; i++) {
        cin >> C[i];
        ok[i][i] = false;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++) bfs(i);
    ll ans = 0;

    for (int b = 2; b <= n; ++b)
        for (int c = 2; c <= n; ++c)
            if (ok[b][c])
                for (int a : f[b])
                    for (int d : f[c])
                        if (a != c && b != d && a != d) {
                            ans = max(ans, C[a] + C[b] + C[c] + C[d]);
                            //                            cout << a << ' ' << b
                            //                            << ' ' << c << ' ' <<
                            //                            d << ' '<< endl;
                        }
    printf("%lld\n", ans);
    return 0;
}
