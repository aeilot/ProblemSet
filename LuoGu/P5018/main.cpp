#include <cstdio>
#include <iostream>

using namespace std;

int sons[1000010][2];
int W[1000010];
int msize = 1;
int size[1000010];

void pre(int x) {
    size[x] = 1;
    if (sons[x][0] != -1) {
        pre(sons[x][0]);
        size[x] += size[sons[x][0]];
    }
    if (sons[x][1] != -1) {
        pre(sons[x][1]);
        size[x] += size[sons[x][1]];
    }
}

bool dfs(int l, int r) {
    if (l == -1 && r != -1) return false;
    if (l == -1 && r == -1) return true;
    if (l != -1 && r == -1) return false;
    if (W[l] != W[r]) return false;
    bool ans = false;
    if (dfs(sons[l][0], sons[r][1]) && dfs(sons[l][1], sons[r][0])) {
        ans = true;
    }
    return ans;
}

int main() {
    // Type your code here
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> W[i];
    for (int i = 1; i <= n; i++) {
        cin >> sons[i][0] >> sons[i][1];
    }
    pre(1);
    for (int i = 1; i <= n; i++) {
        if (dfs(sons[i][1], sons[i][0])) {
            msize = max(msize, size[i]);
        }
    }
    cout << msize << endl;
    return 0;
}