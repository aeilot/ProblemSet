#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

#define MAXN 100000

struct Node {
    int to, next;
} NDS[MAXN];

int cnt = 0;
int head[101];

void add(int x, int y) {
    NDS[cnt].to = y;
    NDS[cnt].next = head[x];
    head[x] = cnt++;
}

stack<int> st;
int idc = 0, id[MAXN], dfn[MAXN], low[MAXN];
bool vis[MAXN];
int cc = 0;
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
    if (low[x] == dfn[x]) {
        int now = st.top();
        ++idc;
        do {
            now = st.top();
            st.pop();
            id[now] = idc;
            vis[now] = 0;
        } while (now != x);
    }
}

int deg[MAXN], degO[MAXN];

void add2(int x, int y) {
    deg[y]++;
    degO[x]++;
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        while (1) {
            int tmp;
            cin >> tmp;
            if (tmp == 0) break;
            add(i, tmp);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = head[i]; j != -1; j = NDS[j].next) {
            int y = NDS[j].to;
            if (id[y] != id[i]) {
                add2(id[i], id[y]);
            }
        }
    }
    int ans = 0;
    int ans2 = 0;
    for (int i = 1; i <= idc; i++) {
        if (deg[i] == 0) {
            ans++;
        }
        if (degO[i] == 0) {
            ans2++;
        }
    }
    cout << ans << endl;
    if (idc == 1) {
        cout << 0 << endl;
        return 0;
    }
    cout << max(ans, ans2) << endl;
    return 0;
}