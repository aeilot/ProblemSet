#include <cstdio>
#include <iostream>

using namespace std;

long long MAP[100010];
long long f[100010];

int main() {
    // Type your code here
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> MAP[i];
    }
    long long ans = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if (j < f[i]) break;
            if ((MAP[j] & MAP[i]) != 0) {
                f[i] = max(f[j] + 1, f[i]);
            }
        }
        ans = max(f[i], ans);
    }
    cout << ans << endl;
    return 0;
}