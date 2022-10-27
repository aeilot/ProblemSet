#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long MAP[310];
long long PRE[310];
long long DP[310][310];

int main() {
    memset(DP, 0x3f, sizeof(DP));
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> MAP[i];
        DP[i][i] = 0;
        if (i >= 1)
            PRE[i] = PRE[i - 1] + MAP[i];
        else
            PRE[i] = MAP[i];
    }
    for (int len = 2; len <= N; len++) {
        for (int i = 0; i + len - 1 < N; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + PRE[j] -
                                             (i >= 1 ? PRE[i - 1] : 0));
            }
        }
    }
    cout << DP[0][N - 1] << endl;
    return 0;
}