#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

#define MOD 100000000
int f[300][110][30][2];

int main() {
    // Type your code here
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    f[1][1][1][0] = f[1][0][1][1] =
        1;  // TODO: Method of Initialization Matters
    for (int i = 2; i <= n1 + n2; i++) {  // i standing for current location
        for (int j = 0; j <= min(n1, i); j++) {  // j standing for chosen 1s
            int k = i - j;                       // k standing for chosen 2s
            if (k > n2) {
                continue;
            }
            for (int l = 1; l <= k && l <= k2; l++) {
                if (j >= 1)
                    f[i][j][1][0] =
                        (f[i][j][1][0] + f[i - 1][j - 1][l][1]) % MOD;
            }
            for (int l = 1; l <= j && l <= k1; l++) {
                f[i][j][1][1] = (f[i][j][1][1] + f[i - 1][j][l][0]) % MOD;
            }
            for (int l = 2; l <= j && l <= k1; l++) {
                f[i][j][l][0] = f[i - 1][j - 1][l - 1][0];
            }
            for (int l = 2; l <= k && l <= k2; l++) {
                f[i][j][l][1] = f[i - 1][j][l - 1][1];
            }
        }
    }
    long long ans = 0;
    for (int l = 1; l <= k1; l++) {
        ans = ans + f[n1 + n2][n1][l][0] % MOD;
    }
    for (int l = 1; l <= k2; l++) {
        ans = ans + f[n1 + n2][n1][l][1] % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}