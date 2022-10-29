#include <cstdio>
#include <iostream>

using namespace std;

int MAP[110];
int DP[110];

int main() {
    // Type your code here
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> MAP[i];
    }
    DP[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int k = m; k >= 0; k--) {
            for (int j = 1; j <= MAP[i]; j++) {
                if (k >= j) DP[k] = (DP[k] + DP[k - j]) % 1000007;
            }
        }
    }
    cout << DP[m] % 1000007 << endl;
    return 0;
}