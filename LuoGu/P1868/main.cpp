#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[3000001];
int a[3000001];
vector<int> ve[3000001];

int main() {
    // Type your code here
    int N;
    cin >> N;
    int mx = 0;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;
        ve[y].push_back(x - 1);
        mx = max(mx, y);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= mx; i++) {
        dp[i] = dp[i - 1];
        for (int j = 0; j < ve[i].size(); j++) {
            int b = ve[i][j];
            dp[i] = max(dp[i], dp[b] + i - b);
        }
    }
    cout << dp[mx] << endl;
    return 0;
}