#include <cstdio>
#include <iostream>

using namespace std;

#define MOD 19650827

long long F[1010][1010][2];
/*
分类从左边右边进入
因为不知道上一个添加的是从左边还是右边

对于分类 DP，状态设计
*/
long long MAP[1010];

int main() {
    // Type your code here
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> MAP[i];
        F[i][i][0] = 0;
        F[i][i][1] = 1;
    }
    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len - 1 <= N; i++) {
            int j = i + len - 1;
            if (MAP[i] < MAP[i + 1]) F[i][j][0] += F[i + 1][j][0];
            if (MAP[i] < MAP[j]) F[i][j][0] += F[i + 1][j][1];
            if (MAP[j] > MAP[j - 1]) F[i][j][1] += F[i][j - 1][1];
            if (MAP[j] > MAP[i]) F[i][j][1] += F[i][j - 1][0];
            F[i][j][1] %= MOD;
            F[i][j][0] %= MOD;
        }
    }
    cout << (F[1][N][0] + F[1][N][1]) % MOD << endl;
    return 0;
}