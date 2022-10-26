#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int AR[1000001];
int dp[1000001][3];

int main() {
    // Type your code here
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> AR[i];
    }
    dp[1][AR[1] + 1] = 0;
    for (int i = 2; i <= n; i++) {
        if (AR[i] == -1) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = (AR[i - 1] == 1) ? min(dp[i - 1][0], dp[i - 1][1]) + 1 : dp[0][0];
            dp[i][2] = (AR[i - 1] == 1) ? min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 2 : dp[i - 1][2] + 2;
        } else if (AR[i] == 1) {
            dp[i][0] = dp[i - 1][0] + 2;
            if (AR[i - 1] == -1) dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            else
                dp[i][1] = dp[i - 1][0] + 1;
            dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
        } else {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            if (AR[i - 1] == 1) dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
            else
                dp[i][2] = dp[i - 1][2] + 1;
        }
    }// 操作无序
    int mm = min(dp[n][0], min(dp[n][1], dp[n][2]));
    if (mm >= dp[0][0]) {
        cout << "BRAK" << endl;
    } else {
        cout << mm << endl;
    }
    return 0;
}