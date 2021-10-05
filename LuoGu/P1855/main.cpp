#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int M[101], T[101];
int dp[201][201];  //! 背包DP的数组容量特别需要注意！！！

int main() {
    int n, m, t;  //! 虽然秒杀题，但是变量名不重复这种基础问题一定不能犯！！！
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++) {
        cin >> M[i] >> T[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= M[i]; j--) {
            for (int k = t; k >= T[i]; k--) {
                dp[j][k] = max(dp[j][k], dp[j - M[i]][k - T[i]] + 1);
            }
        }
    }
    cout << dp[m][t] << endl;
    return 0;
}
