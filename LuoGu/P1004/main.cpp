#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int DP[12][12][12][12];
int map[10][10];

int main() {
    int n;
    cin >> n;
    int a = 100;
    while (a != 0) {
        int b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int h = 1; h <= n; h++) {
                for (int k = 1; k <= n; k++) {
                    DP[i][j][h][k] =
                        max(max(DP[i - 1][j][h - 1][k], DP[i - 1][j][h][k - 1]),
                            max(DP[i][j - 1][h - 1][k],
                                DP[i][j - 1][h][k - 1])) +
                        map[i][j] + map[h][k];
                    if (i == h && j == k) DP[i][j][h][k] -= map[i][j];
                }
            }
        }
    }
    cout << DP[n][n][n][n] << endl;
}