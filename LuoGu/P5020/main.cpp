#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> CSys;

int dp[25001];
int w[101];

#define NEED_TO_ADD 2
#define CAN_GET 1

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    CSys.resize(T);
    for (int i = 0; i < T; i++) {
        memset(dp, 0, sizeof(dp));
        int n;
        cin >> n;
        CSys[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> CSys[i][j];
            dp[CSys[i][j]] = NEED_TO_ADD;
        }
        sort(CSys[i].begin(), CSys[i].end());
        for (int j = 0; j <= CSys[i][CSys[i].size()]; j++) {
            if (dp[j] > 0) {
                for (int k : CSys[i]) {
                    if (j + k <= CSys[i][CSys[i].size()])
                        dp[j + k] = 1;
                    else
                        break;
                }
            }
        }
        int ans = 0;
        for (int x = 0; x <= CSys[i].back(); x++)
            if (dp[x] == 2) ans++;
        cout << ans << endl;
    }
    return 0;
}
