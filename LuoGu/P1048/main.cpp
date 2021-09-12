#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct Herb {
    int time;
    int val;
    double p;
    Herb(int a, int b) {
        time = a;
        val = b;
    }
};

vector<Herb> Ma;
int m;
int mem[101][1001];
int dfs(int n, int tleft) {
    if (mem[n][tleft] != -1) return mem[n][tleft];
    if (n >= m) {
        return mem[n][tleft] = 0;
    }
    int dfs1 = dfs(n + 1, tleft);
    int dfs2 = -1000;
    if (tleft >= Ma[n].time) {
        dfs2 = dfs(n + 1, tleft - Ma[n].time) + Ma[n].val;
    }
    return mem[n][tleft] = max(dfs1, dfs2);
}

int main() {
    int t = 0;
    cin >> t >> m;
    memset(mem, -1, sizeof(mem));
    for (int i = 0; i < m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        Herb tmp = Herb(t1, t2);
        Ma.push_back(tmp);
    }
    int ans = dfs(0, t);
    cout << ans << endl;
    return 0;
}