#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Edge {
public:
    int u, v;
    Edge(int u, int v) {
        this->u = u;
        this->v = v;
    }
};

class BGraph {
public:
    int lc, rc;
    vector<vector<Edge>> LE, RE;

    BGraph(int lc, int rc) {
        this->lc = lc;
        this->rc = rc;
        LE.resize(lc);
        RE.resize(rc);
    }

    void addEdge(int u, int v) {
        LE[u].push_back({u, v});
        RE[v].push_back({v, u});
    }

    void Hungary() {
        mark.resize(rc, 0);
        matched.resize(rc, -1);
        for (int i = 0; i < lc; i++) {
            for (int j = 0; j < mark.size(); j++) {
                mark[j] = 0;
            }
            DFS_H(i);
        }
        int ans = 0;
        for (int i : matched) {
            if (i != -1) ans++;
        }
        cout << ans << endl;
    }

protected:
    vector<int> mark;
    vector<int> matched;
    bool DFS_H(int start) {
        for (auto i : LE[start]) {
            if (mark[i.v] == 1) continue;
            mark[i.v] = 1;
            if (matched[i.v] == -1 || DFS_H(matched[i.v])) {
                matched[i.v] = start;
                return true;
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m, e;
    cin >> n >> m >> e;
    BGraph bg(n, m);
    while (e--) {
        int a, b;
        cin >> a >> b;
        bg.addEdge(a - 1, b - 1);
    }
    bg.Hungary();
    return 0;
}