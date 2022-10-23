#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Tr {
    int from, to, next;
} ed[400001];
int head[400001];
int vis[400001];
int w[200001];
int d[200001];
int ans = -1;
int cnt = 0;

void build(int a, int b) {
    ed[cnt].from = a;
    ed[cnt].to = b;
    ed[cnt].next = head[a];
    head[a] = cnt++;
}

void dfs(int x) {
    vis[x] = 1;
    for (int i = head[x]; i != -1; i = ed[i].next) {
        int y = ed[i].to;
        if (vis[y] == 1) continue;
        d[y] = d[x] + 1;
        if (d[y] % 2 == 1) {
            if (ans == -1)
                ans = w[y];
            else
                ans = ans ^ w[y];
        }
        dfs(y);
    }
}

int main() {
    // Type your code here
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(head, -1, sizeof(head));
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        memset(w, 0, sizeof(w));
        cnt = 0;
        int n;
        cin >> n;
        for (int j = 1; j < n; j++) {
            int tmp;
            cin >> tmp;
            build(j, tmp);
            build(tmp, j);
        }
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            w[j] = tmp;
        }
        ans = -1;
        dfs(0);
        cout << (ans == 0 ? "lose" : "win") << endl;
    }
    return 0;
}