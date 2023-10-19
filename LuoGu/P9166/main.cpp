#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

struct SG {
    int l, r;
} F[200010];

bool v[200010];

bool cmp(const SG& a, const SG& b) {
    if (a.l == b.l) {
        return a.r < b.r;
    }
    return a.l < b.l;
}

int main() {
    // Type your code here
    int mmin = INT_MAX;
    int mmax = 0;
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        F[i].l = l;
        F[i].r = r;
        if (x >= F[i].l && x <= F[i].r) {
            mmax = max(mmax, F[i].r);
            mmin = min(mmin, F[i].l);
            v[F[i].l] = v[F[i].r] = 1;
        }
    }
    sort(F + 1, F + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        if (F[i].l >= mmin && F[i].l <= mmax) {
            mmax = max(F[i].r, mmax);
        }
    }
    for (int i = m; i >= 1; i--) {
        if (F[i].r >= mmin && F[i].r <= mmax) {
            mmin = min(F[i].l, mmin);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (F[i].l < mmin || F[i].r > mmax) continue;
        if (F[i].r < x) {
            v[F[i].l] = 1;
        } else {
            v[F[i].r] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] && i != x) {
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}
