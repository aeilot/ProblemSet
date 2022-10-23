#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int st[36];
int dp[36][36];

int main() {
    // Type your code here
    memset(dp, 0, sizeof(dp));
    int n, m;
    cin >> n >> m;
    int flag = -1;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        st[i] = tmp % m;
        dp[i][i] = st[i];
        if (tmp % m != 0) flag = 0;
    }
    if (flag == -1)
        cout << 0 << endl;
    else {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                for (int k = i + 1; k < j; k++) {
                    for (int z = k; z < j; z++) {
                        dp[i][j] = max(max((dp[i][i] + dp[k][z]) % m, dp[k][z]),
                                       max(dp[i][j], dp[i][i]));
                    }
                }
            }
        }
        cout << dp[0][n - 1] % m << endl;
    }
    return 0;
}