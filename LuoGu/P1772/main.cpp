#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int ADD[27], RM[27];
long long DP[2010][2010];

int main() {
    // Type your code here
    string str;
    int n, m;
    cin >> n >> m;
    cin >> str;
    for (int i = 1; i <= n; i++) {
        char a;
        int ad, r;
        cin >> a >> ad >> r;
        ADD[a - 'a'] = ad;
        RM[a - 'a'] = r;
    }
    memset(DP, 0x3f, sizeof(DP));
    for (int i = 0; i < str.size(); i++) {
        DP[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < i; j++) {
            DP[i][j] = 0;
        }
    }
    for (int len = 2; len <= m; len++) {
        for (int i = 0; i + len - 1 < m; i++) {
            int j = i + len - 1;
            DP[i][j] = min(DP[i][j], DP[i + 1][j] + ADD[str[i] - 'a']);
            DP[i][j] = min(DP[i][j], DP[i + 1][j] + RM[str[i] - 'a']);
            DP[i][j] = min(DP[i][j], DP[i][j - 1] + ADD[str[j] - 'a']);
            DP[i][j] = min(DP[i][j], DP[i][j - 1] + RM[str[j] - 'a']);
            if (str[i] == str[j]) DP[i][j] = min(DP[i][j], DP[i + 1][j - 1]);
        }
    }
    cout << DP[0][m - 1] << endl;
    return 0;
}