#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int to, next;
} NDS[200010];

int dfn[20010], low[20010], head[20010], cnt = 0;
void add(int x, int y) {
    NDS[cnt].next = head[x];
    NDS[cnt].to = y;
    head[x] = cnt++;
}

int cc = 0;
bool cu[20010];
void tarjan(int s, int fa) {
    dfn[s] = low[s] = ++cc;
    int child = 0;
    for (int i = head[s]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (!dfn[y]) {
            tarjan(y, fa);
            low[s] = min(low[s], low[y]);
            if (low[y] >= dfn[s] && s != fa) cu[s] = 1;
            if (s == fa) child++;
        }
        low[s] = min(low[s], dfn[y]);
    }
    if (child >= 2 && s == fa) {
        cu[s] = 1;
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
        add(y, x);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, i);
        }
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (cu[i]) tot++;
    }
    cout << tot << endl;
    for (int i = 1; i <= n; i++) {
        if (cu[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}