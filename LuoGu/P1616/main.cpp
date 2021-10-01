#include <cstdio>
#include <iostream>

using namespace std;

#define LL long long

const int maxm = 10000, maxt = 10000000;
LL v[maxm], w[maxm];
LL dp[maxt];

int main(int argc, char *argv[]) {
    int t, m;
    cin >> t >> m;
    for (int i = 0; i < m; i++) cin >> w[i] >> v[i];
    for (int i = 0; i < m; i++)
        for (int j = w[i]; j <= t; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[t] << endl;
    return 0;
}
