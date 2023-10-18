#include <cstdio>
#include <iostream>

using namespace std;

#define MOD 1000000007

int A[100010];
int f[100010];
// f[i][j] = sum of f[i-1][j] and (if j|A[i]) f[i-1][j-1]

int main() {
    // Type your code here
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            if (A[i] % j == 0) {
                f[j] = f[j] + f[j - 1] % MOD;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}