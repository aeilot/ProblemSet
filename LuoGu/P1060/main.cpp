#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int w[26], v[26];
int dp[30001];//! 背包DP的数组容量特别需要注意！！！

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int tw, tv;
        cin >> tw >> tv;
        w[i] = tw;
        v[i] = tw * tv;
        dp[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = n; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
