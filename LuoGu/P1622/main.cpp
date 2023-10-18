#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int NL[110];
int DP[110][110];

int main() {
    // Type your code here
    int P, Q;
    cin >> P >> Q;
    int mmax = 0;
    for (int i = 1; i <= Q; i++) {
        cin >> NL[i];
        mmax = max(mmax, NL[i]);
    }
    NL[Q + 1] = P + 1;
    for (int k = 1; k <= Q; k++) {
        for (int i = 1; i + k - 1 <= Q; i++) {
            int y = i + k - 1;
            DP[i][y] = INT_MAX;
            for (int m = i; m <= y; m++) {
                DP[i][y] = min(DP[i][m - 1] + DP[m + 1][y], DP[i][y]);
            }
            DP[i][y] += NL[y + 1] - NL[i - 1] - 2;
        }
    }
    cout << DP[1][Q] << endl;
    return 0;
}