#include <cstdio>
#include <iostream>

using namespace std;

long long DP[61][270007];

int main() {
    // Type your code here
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int in;
        cin >> in;
        DP[in][i] = i + 1;
    }
    long long ans = 0;
    for (int i = 2; i <= 58; i++) {
        for (int j = 1; j <= N; j++) {
            if (!DP[i][j]) {
                DP[i][j] = DP[i - 1][DP[i - 1][j]];
            }
            if (DP[i][j]) {
                ans = i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}