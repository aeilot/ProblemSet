#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

#define MOD 1000000007

long long A[1000010];
long long f[1000010];
long long w[1000010];
// f[i][j] = sum of f[i-1][j] and (if j|A[i]) f[i-1][j-1]

int main() {
    // Type your code here
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> A[i];
    }
    f[0] = 1;
    for (long long i = 1; i <= n; i++) {
        long long top = 0, qq = sqrt(A[i]);
        for (long long j = 1; j <= qq; j++) {
            if (A[i] % j == 0) {
                w[++top] = j;
                if (j * j != A[i]) {
                    w[++top] = A[i] / j;
                }
            }
        }
        sort(w + 1, w + top + 1);
        for (int j = top; j >= 1; j--) {
            f[w[j]] = f[w[j]] + f[w[j] - 1] % MOD;
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