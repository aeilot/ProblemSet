#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

struct Task {
    int x, y, t;
} tsk[100010];

bool cmp(Task &a, Task &b) { return a.t < b.t; }

int fa[1010];

int find(int x) { return (x == fa[x]) ? x : fa[x] = find(fa[x]); }

void unite(int x, int y) { fa[find(x)] = find(y); }

int n, m;

bool check() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == fa[i]) {
            cnt++;
        }
        if (cnt == 2) {
            return false;
        }
    }
    return cnt == 1;
}

int main() {
    // Type your code here
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> tsk[i].x >> tsk[i].y >> tsk[i].t;
    }
    sort(tsk + 1, tsk + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        unite(tsk[i].x, tsk[i].y);
        if (check()) {
            cout << tsk[i].t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}