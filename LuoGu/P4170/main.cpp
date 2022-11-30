#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int DP[51][51];

int main() {
    // Type your code here
    memset(DP, 0x3f, sizeof(DP));
    string dst;
    cin >> dst;
    for (int i = 0; i < dst.size(); i++) {
        DP[i][i] = 1;
    }
    for (int len = 2; len <= dst.size(); len++) {
        for (int i = 0; i + len <= dst.size(); i++) {
            int j = i + len - 1;
            if (dst[i] == dst[j]) {
                DP[i][j] = min(DP[i + 1][j], DP[i][j - 1]);
            } else {
                for (int k = i; k < j; k++) {
                    DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j]);
                }
            }
        }
    }
    cout << DP[0][dst.size() - 1] << endl;
    return 0;
}
