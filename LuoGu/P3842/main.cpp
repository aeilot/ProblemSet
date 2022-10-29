#include <cstdio>
#include <iostream>

using namespace std;

int L[20010], R[20010], LEN[20010];
int DP[2][2];

int main() {
    // Type your code here
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
        LEN[i] = abs(R[i] - L[i]);
    }
    L[0] = R[0] = 1;
    LEN[0] = LEN[n + 1] = 0;
    L[n + 1] = R[n + 1] = n;
    DP[1][0] = DP[1][1] = -1;
    for (int i = 0, j = 1; j <= n + 1; j++, i ^= 1) {
        DP[i][0] = min(DP[i ^ 1][1] + abs(L[j - 1] - L[j]),
                       DP[i ^ 1][0] + abs(R[j - 1] - L[j])) +
                   1 + LEN[j];
        DP[i][1] = min(DP[i ^ 1][1] + abs(L[j - 1] - R[j]),
                       DP[i ^ 1][0] + abs(R[j - 1] - R[j])) +
                   1 + LEN[j];
    }
    cout << min(DP[n % 2][0], DP[n % 2][1]) - 1 << endl;
    return 0;
}