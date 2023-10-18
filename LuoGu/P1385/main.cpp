#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

#define MOD 1000000007
int f[110][3010];

// f[i][j] = sum of f[i-1][j] and f[i-1][j-V]

void solve() {
    for (int i = 0; i < 26; i++) {
        f[1][i] = 1;
    }
    for (int i = 2; i <= 100; i++) {
        // f[i][0] = 1;
        for (int j = 0; j <= 3000; j++) {
            for (int k = 0; k < 26; k++) {
                if (j >= k) f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;
            }
        }
    }
}

int main() {
    // Type your code here
    int T;
    scanf("%d", &T);
    solve();
    while (T--) {
        string str;
        cin >> str;
        int sum = 0;
        for (int i = 0; i < str.size(); i++) sum += str[i] - 'a';
        cout << (f[str.size()][sum] - 1 % MOD) << endl;
    }
    return 0;
}