#include <bits/stdc++.h>
using namespace std;
int n, m, a[1050000], pr[10500000], cnt[10500000];
int pre[10500000], l, r;
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 2; i <= 10000000; i++) pr[i] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 2; i <= 10000000; i++) {
        if (pr[i]) {
            pre[i] += cnt[i];
            for (int j = i * 2; j <= 10000000; j += i) {
                pre[i] += cnt[j];
                pr[j] = 0;
            }
        }
    }
    for (int i = 2; i <= 10000000; i++) pre[i] += pre[i - 1];
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }
    return 0;
}