#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int PRE[101][101];
int MAP[101][101];

int main() {
    // Type your code here
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> MAP[i][j];
            PRE[i][j] =
                    MAP[i][j] + PRE[i][j - 1] + PRE[i - 1][j] - PRE[i - 1][j - 1];
        }
    }
    for (int k = min(n, m); k > 0; k--) {
        for (int i = 1; i + k - 1 <= n; i++) {
            for (int j = 1; j + k - 1 <= m; j++) {
                int pp = PRE[i + k - 1][j + k - 1] + PRE[i - 1][j - 1] -
                         PRE[i - 1][j + k - 1] - PRE[i + k - 1][j - 1];
                if (pp == k * k) {
                    cout << k << endl;
                    return 0;
                }
            }
        }
    }
    cout << 0 << endl;
    return 0;
}