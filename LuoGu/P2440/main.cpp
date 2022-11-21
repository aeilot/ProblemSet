#include <cstdio>
#include <iostream>

using namespace std;

long long AR[100010];
int n, k;
long long ans;

bool check(long long x) {
    if (x == 0) return false;
    long long num = 0;
    for (int i = 1; i <= n; i++) {
        num += AR[i] / x;
    }
    if (num >= k) ans = max(ans, x);
    return num >= k;
}

int main() {
    // Type your code here
    cin >> n >> k;
    long long l = 1, r, mid;
    for (int i = 1; i <= n; i++) {
        cin >> AR[i];
        r = max(r, AR[i]);
    }
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << ans << endl;
    return 0;
}