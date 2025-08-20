#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int W[20];
int DP[20][300000];
int cnt = 0;

int main() {
    int n, mw;
    cin >> n >> mw;
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }
    int up = 1 << n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= up - 1; j++) {
            DP[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 0; i < n; i++) {
        DP[1][1 << i] = W[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= up - 1; j++) {
            if (DP[i][j] == 0x3f3f3f3f) continue;
            for (int k = 0; k < n; k++) {
                if ((j & (1 << k)) != 0) continue;
                if (DP[i][j] + W[k] <= mw) {
                    DP[i][j | (1 << k)] =
                            min(DP[i][j | (1 << k)], DP[i][j] + W[k]);
                } else {
                    DP[i + 1][j | (1 << k)] = min(DP[i][j | (1 << k)], W[k]);
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (DP[i][up - 1] != 0x3f3f3f3f) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
