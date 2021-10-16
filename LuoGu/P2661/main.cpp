#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > gp;

int dst, n;
int dfs(int i, int rd) {
    if (rd > n) return rd;
    if (rd > 0 && i == dst) {
        return rd;
    }
    for (int j = 0; j < gp[i].size(); j++) {
        return dfs(gp[i][j], rd + 1);
    }
}

int main() {
    cin >> n;
    gp.resize(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        gp[i].push_back(a - 1);
    }
    int mmin = INT_MAX;
    for (int i = 0; i < n; i++) {
        dst = i;
        mmin = min(mmin, dfs(i, 0));
    }
    cout << mmin << endl;
    return 0;
}