#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool ok[10000010];
int nx[10000010];
int cnt = 0;

bool check(int x) {
    while (x > 0) {
        int bt = x % 10;
        if (bt == 7) return true;
        x /= 10;
    }
    return false;
}

void init() {
    int lst = 0;
    for (int i = 1; i <= 10000001; i++) {
        if (ok[i] == 0) continue;
        if (check(i)) {
            ok[i] = 0;
            for (int j = 2; j * i <= 10000001; j++) {
                int tt = i * j;
                if (ok[tt] == 1) ok[tt] = 0;
            }
        } else {
            nx[lst] = i;// 记录 NX 优化时间
            lst = i;
        }
    }
}

int bs(int x) {
    int i = x + 1;
    while (1) {
        if (ok[i]) return i;
        i += 1;
        if (i >= 10000010) return -1;
    }
    return -1;
}

int main() {
    memset(ok, 1, sizeof(ok));
    int t;
    cin >> t;
    init();
    while (t--) {
        int n;
        cin >> n;
        cout << ((ok[n] == 0) ? -1 : nx[n]) << endl;
    }
}
