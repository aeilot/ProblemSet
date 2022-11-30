#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int to, next;
} NDS[100010];

int cnt = 0;
int head[100010];
bool vis[100010];
int dfn[100010], si[100010], du[100010], low[100010], id[100010];
int cc = 0;

void add(int x, int y) {
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    head[x] = cnt++;
}

stack<int> st;
int ans = 0;

void tarjan(int x) {
    dfn[x] = low[x] = ++cc;
    vis[x] = 1;
    st.push(x);
    for (int i = head[x]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (vis[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {
        int now = st.top();
        ans++;
        do {
            si[ans]++;
            now = st.top();
            id[now] = ans;
            st.pop();
            vis[now] = 0;
        } while (now != x);
    }
}

int main() {
    memset(head, -1, sizeof(head));
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = head[i]; j != -1; j = NDS[j].next) {
            int y = NDS[j].to;
            if (id[i] != id[y]) {
                du[id[i]]++;
            }
        }
    }
    int u = 0;
    int aa = 0;
    for (int i = 1; i <= ans; i++) {
        if (!du[i]) {
            u++;
            aa = si[i];
        }
    }
    if (u == 1) {
        cout << aa << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}