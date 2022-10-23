#include <cstdio>
#include <iostream>

using namespace std;

long long l[200001];

int main() {
    // Type your code here
    int n;
    long long g, r;
    cin >> n >> g >> r;
    long long inter = g + r;
    for (int i = 0; i <= n; i++) {
        int tmp;
        cin >> tmp;
        if (i >= 1)
            l[i] = l[i - 1] + tmp;
        else
            l[i] = tmp;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        long long ans = t + l[n];
        long long accumulate = 0;
        for (int j = 0; j < n; j++) {
            long long tt = l[j] + t + accumulate;
            long long k = tt / inter;
            if (tt >= (k + 1) * g + k * r && tt < (k + 1) * g + (k + 1) * r) {
                long long add = (k + 1) * g + (k + 1) * r - tt;
                ans += add;
                accumulate += add;
            }
        }
        cout << ans << endl;
    }
    return 0;
}