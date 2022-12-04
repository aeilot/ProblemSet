#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node {
    int to, next;
} NDS[4000010];

int dfn[500010], low[500010], head[500010], cnt = 0;
void add(int x, int y) {
    NDS[cnt].next = head[x];
    NDS[cnt].to = y;
    head[x] = cnt++;
}

int cc = 0;
int num = 0;
stack<int> st;
vector<int> bcc[500010];
void tarjan(int s, int fa) {
    dfn[s] = low[s] = ++cc;
    int child = 0;
    if (s == fa && head[fa] == -1) {
        bcc[++num].push_back(s);
        return;
    }
    st.push(s);
    for (int i = head[s]; i != -1; i = NDS[i].next) {
        int y = NDS[i].to;
        if (!dfn[y]) {
            tarjan(y, fa);
            low[s] = min(low[s], low[y]);
            if (low[y] >= dfn[s]) {
                int tt;
                num++;
                do {
                    tt = st.top();
                    bcc[num].push_back(tt);
                    st.pop();
                } while (tt != y);
                bcc[num].push_back(s);
            }
        } else
            low[s] = min(low[s], dfn[y]);
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
        if (x == y) continue;
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, i);
        }
    }
    cout << num << endl;
    for (int i = 1; i <= num; i++) {
        cout << bcc[i].size() << " ";
        for (int j = 0; j < bcc[i].size(); j++) {
            cout << bcc[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}