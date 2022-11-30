#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    vector<int> fa;

    DSU(int size) {
        fa.resize(size + 1);
        for (int i = 1; i <= size; i++) {
            fa[i] = i;
        }
    }

    int find(int x) { return (fa[x] == x) ? x : fa[x] = find(fa[x]); }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        fa[x] = y;
    }
};

int main() {
    // Type your code here
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            dsu.unite(b, c);
        } else {
            cout << ((dsu.find(b) == dsu.find(c)) ? "Y" : "N") << endl;
        }
    }
    return 0;
}