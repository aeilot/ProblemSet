#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int A[7];
int st[120010];
int cnt = 0;
int tv = 0;
int F[120010];

void solve() {
    memset(F, 0, sizeof(F));
    F[0] = 1;
    for (int t = 1; t <= cnt; t++) {
        for (int y = tv; y >= st[t]; y--) {
            F[y] = (F[y - st[t]] || F[y]);
        }
    }
}

int main() {
    // Type your code here
    int cns = 1;
    while (1) {
        tv = 0;
        memset(A, 0, sizeof(A));
        bool fg = false;
        for (int i = 1; i <= 6; i++) {
            cin >> A[i];
            tv += A[i] * i;
            if (A[i] != 0) fg = true;
        }
        if (!fg) break;
        cout << "Collection #" << cns << ":" << endl;
        cns++;
        if (tv & 1) {
            cout << "Can't be divided." << endl << endl;
            continue;
        }
        cnt = 0;
        for (int i = 1; i <= 6; i++) {
            int z = 1;
            while (A[i] >= z) {
                st[++cnt] = i * z;
                A[i] -= z;
                z *= 2;
            }
            if (A[i] != 0) {
                st[++cnt] = A[i] * i;
            }
        }
        tv /= 2;
        solve();
        if (F[tv]) {
            cout << "Can be divided." << endl;
        } else {
            cout << "Can't be divided." << endl;
        }
        cout << endl;
    }
    return 0;
}