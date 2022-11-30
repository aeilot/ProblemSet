#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int to, next;
} NDS[50010];

int cnt = 0, head[10010];
int dfn[10010], low[10010], vis[10010];

void add(int x, int y) {
    NDS[cnt].next = head[x];
    NDS[cnt].to = y;
    head[x] = cnt++;
}

int cc = 0;
int aa = 0;
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
        aa = 0;
        do {
            now = st.top();
            st.pop();
            aa++;
            vis[now] = 0;
        } while (now != x);
        if (aa > 1) {
            ans++;
        }
    }
}

int main() {
    // Type your code here
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
    cout << ans << endl;
    return 0;
}