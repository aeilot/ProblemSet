#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int MAP[300];
int DP[300][300];

int main() {
    // Type your code here
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> MAP[i];
    }
    memset(DP, 0, sizeof(DP));
    for (int i = 1; i <= n; i++) {
        DP[i][i] = MAP[i];
    }
    int ans = 0;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            for (int k = i; k < i + len - 1; k++) {
                if (DP[i][k] == DP[k + 1][i + len - 1]) {
                    DP[i][i + len - 1] = max(DP[i][i + len - 1], DP[i][k] + 1);
                    ans = max(ans, DP[i][k] + 1);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}