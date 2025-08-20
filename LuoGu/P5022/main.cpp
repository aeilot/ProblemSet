#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

struct Node {
    int to, next;
} NDS[20001];
int head[5001];
int cnt = 0;

void add(int u, int v) {
    NDS[cnt].to = v;
    NDS[cnt].next = head[u];
    head[u] = cnt++;
}
int n, m;
bool vis[5001];
void dfs(int x) {
    cout << x << ' ';
    vis[x] = 1;
    priority_queue<int, vector<int>, std::greater<int>> pq;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y]) continue;
        pq.push(y);
    }
    while (!pq.empty()) {
        int t = pq.top();
        pq.pop();
        dfs(t);
    }
}

int d1, d2;

bool cmp(vector<int> &a, vector<int> &b) {// <
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (a[i] > b[i]) return false;
    }
    return true;
}

vector<int> ans;
vector<int> tta;
void dfs2(int x) {
    tta.push_back(x);
    vis[x] = 1;
    priority_queue<int, vector<int>, std::greater<int>> pq;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (vis[y] || (x == d1 && y == d2) || (x == d2 && y == d1)) continue;
        pq.push(y);
    }
    while (!pq.empty()) {
        int t = pq.top();
        pq.pop();
        dfs2(t);
    }
}

int f[5001];
vector<int> cir;
int l, r;
void get_loop(int x, int fa) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (y == fa) continue;
        if (vis[y]) {
            l = y;
            r = x;
            return;
        }
        if (vis[y]) continue;
        f[y] = x;
        get_loop(y, x);
    }
}
void lop(int x) {
    //    cout << x << endl;
    cir.push_back(x);
    if (x == r) return;
    x = f[x];
    lop(x);
}

int main() {
    memset(head, -1, sizeof(head));
    std::ios::sync_with_stdio(0);
    // Type your code here
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    if (m == n - 1) {
        dfs(1);
        cout << endl;
    } else {
        get_loop(1, 0);
        lop(l);
        //        for(int i = 0; i<cir.size(); i++) cout << cir[i] << endl;
        d1 = l;
        d2 = r;
        memset(vis, 0, sizeof(vis));
        //        cout << l << ' ' << r << endl;
        dfs2(1);
        ans = tta;
        //        cout << endl;
        for (int i = 0; i < cir.size() - 1; i++) {
            memset(vis, 0, sizeof(vis));
            tta.clear();
            d1 = cir[i];
            d2 = cir[i + 1];
            //            cout << d1 << ' ' << d2 << endl;
            dfs2(1);
            if (tta < ans) ans = tta;
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
