#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int ans[100000000];
int f[100000000];
int cnt = 0;

int main() {
    // Type your code here
    int n, q;
    cin >> n >> q;
    memset(f, 0, sizeof(f));
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (f[i] == 0) {
            ans[cnt++] = i;
        }
        for (int j = 0; j < cnt && ans[j] * i <= n; j++) {
            f[ans[j] * i] = 1;
            if (i % ans[j] == 0) break;
        }
    }
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        cout << ans[t - 1] << endl;
    }
    return 0;
}