#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 500001
#define MUL_MAX 22

vector<int> tree[MAX];// 以邻接表形式存储
int dep[MAX];
int fas[MAX][MUL_MAX];
bool first = true;

int lg2(int x) {
    return log(x) / log(2) + 1;
}

void dfs(int x, int fa) {
    if (fa != -1) {
        dep[x] = dep[fa] + 1;
    }
    fas[x][0] = fa;
    for (int i = 1; (1 << i) <= dep[x]; i++) {
        fas[x][i] = fas[fas[x][i - 1]][i - 1];
    }
    for (int i = 0; i < tree[x].size(); i++) {
        if (tree[x].at(i) != fa) dfs(tree[x].at(i), x);
    }
}

int solve(int a, int b) {
    if (dep[b] > dep[a]) swap(a, b);
    while (dep[a] > dep[b]) {
        a = fas[a][lg2(dep[a] - dep[b]) - 1];
    }
    if (a == b) return a;
    for (int i = lg2(dep[a]); i >= 0; i--) {
        if (fas[a][i] != fas[b][i]) {
            a = fas[a][i];
            b = fas[b][i];
        }
    }
    return fas[a][0];
}

int LCA(int a, int b, int r) {
    if (first) {
        dep[r] = 0;
        fas[r][0] = -1;
        dfs(r, -1);
        first = false;
    }
    int res;
    res = solve(a, b);
    return res;
}

int main(int argc, char *argv[]) {
    int m, n, s;
    cin >> m >> n >> s;
    for (int i = 0; i < MAX; i++) {
        dep[i] = 0;
        for (int j = 0; j < MUL_MAX; j++)
            fas[i][j] = -2;
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int res = LCA(a, b, s);
        cout << res << endl;
    }
    return 0;
}
