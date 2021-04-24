#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 500000

vector<int> tree[MAX];// 以邻接表形式存储
int dep[MAX];
int fas[MAX];
bool first = true;

void dfs(int x, int fa) {
    if (fa != -1) {
        dep[x] = dep[fa] + 1;
    }
    fas[x] = fa;
    for (int i = 0; i < tree[x].size(); i++) {
        if (fas[tree[x].at(i)] == -2) dfs(tree[x].at(i), x);
    }
}


int solve(int a, int b) {
    while (1) {
        if (a == b) {
            return a;
        } else if (fas[a] == fas[b]) {
            return fas[a];
        } else if (fas[b] == a) {
            return a;
        } else if (fas[a] == b) {
            return b;
        }
        int da = dep[a], db = dep[b];
        int delta = abs(da - db);
        if (da > db) {
            for (int i = 0; i < delta; i++) {
                a = fas[a];
                da = dep[a];
            }
        } else if (da < db) {
            for (int i = 0; i < delta; i++) {
                b = fas[b];
                db = dep[b];
            }
        } else {
            a = fas[a];
            da = dep[a];
        }
    }
    return -1;
}
int LCA(int a, int b, int r) {
    if (first) {
        dep[r] = 0;
        fas[r] = -1;
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
        fas[i] = -2;
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
