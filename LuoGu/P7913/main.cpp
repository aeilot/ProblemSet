#include <cstdio>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

set<pair<int, int>> fls_dom;
set<pair<int, int>> fls_int;
long long F[100010], G[100010];
int n, d, in;

int main() {
    // Type your code here
    cin >> n >> d >> in;
    F[0] = G[0] = 0;
    for (int i = 0; i < d; i++) {
        int l, r;
        cin >> l >> r;
        fls_dom.insert({l, r});
    }
    for (int i = 1; i <= n; i++) {
        int now = 0;
        int cnt = 0;
        while (1) {
            set<pair<int, int>>::iterator iter =
                    fls_dom.lower_bound({now, now});
            if (iter == fls_dom.end()) break;
            now = iter->second;
            cnt++;
            fls_dom.erase(iter);
        }
        F[i] = F[i - 1] + cnt;
    }
    for (int i = 0; i < in; i++) {
        int l, r;
        cin >> l >> r;
        fls_int.insert({l, r});
    }
    for (int i = 1; i <= n; i++) {
        int now = 0;
        int cnt = 0;
        while (1) {
            set<pair<int, int>>::iterator iter =
                    fls_int.lower_bound({now, now});
            if (iter == fls_int.end()) break;
            now = iter->second;
            cnt++;
            fls_int.erase(iter);
        }
        G[i] = G[i - 1] + cnt;
    }
    long long mmax = 0;
    for (int i = 0; i <= n; i++) {
        mmax = max(mmax, F[i] + G[n - i]);
    }
    cout << mmax << endl;
    return 0;
}