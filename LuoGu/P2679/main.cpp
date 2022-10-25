#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

#define MOD 1000000007

string a, b;
long long dp[2][201][201][2];//重点是 0-1 分类

int main() {
    // Type your code here
    int n, m, k;
    cin >> n >> m >> k;
    cin >> a >> b;
    int val = 1;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = dp[1][0][0][0] = 1;
    for (int i = 1; i <= a.size(); i++, val ^= 1) {
        for (int j = 1; j <= b.size(); j++) {
            for (int z = 1; z <= k; z++) {
                if (a[i - 1] != b[j - 1]) {
                    dp[val][j][z][0] = (dp[val ^ 1][j][z][0] + dp[val ^ 1][j][z][1]) % MOD;
                    dp[val][j][z][1] = 0;
                } else {
                    dp[val][j][z][0] = (dp[val ^ 1][j][z][0] + dp[val ^ 1][j][z][1]) % MOD;
                    dp[val][j][z][1] = (dp[val ^ 1][j - 1][z - 1][1] + dp[val ^ 1][j - 1][z - 1][0] + dp[val ^ 1][j - 1][z][1]) % MOD;
                }
            }
        }
    }
    cout << (dp[n & 1][b.size()][k][0] + dp[n & 1][b.size()][k][1]) % MOD << endl;
    return 0;
}