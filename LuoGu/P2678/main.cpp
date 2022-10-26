#include <cstdio>
#include <iostream>

using namespace std;

int a[50002];

int l, n, m;

bool check(int x) {
    int tot = 0;
    int now = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] - a[now] < x) {
            tot++;
        } else {
            now = i;
        }
    }
    return tot <= m;
}

int main() {
    // Type your code here
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = l;
    int lft = 0, rgt = l;
    int mid = lft + ((rgt - lft) >> 1);
    int ans = 0;
    while (lft <= rgt) {
        mid = lft + ((rgt - lft) >> 1);
        if (check(mid)) {
            ans = mid;
            lft = mid + 1;
        } else {
            rgt = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}