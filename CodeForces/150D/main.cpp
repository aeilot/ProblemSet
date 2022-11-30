#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

long long F[121][121], DP[121], G[121][121][121];
long long V[121];

int main() {
    // Type your code here
    memset(F, -0x3f, sizeof(F));
    memset(G, -0x3f, sizeof(G));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> V[i];
    }
    string tmp;
    cin >> tmp;
    for (int i = 0; i < tmp.size(); i++) {
        if (V[1] >= 0) F[i][i] = V[1];
        G[i][i][1] = 0;
        G[i][i][0] = F[i][i];
    }
    for (int i = 0; i < tmp.size() - 1; i++) {
        if (V[1] >= 0) G[i][i + 1][1] = V[1], F[i][i + 1] = 2 * V[1];
        if (tmp[i] == tmp[i + 1]) {
            G[i][i + 1][2] = 0;
            if (V[2] >= 0) F[i][i + 1] = max(F[i][i + 1], V[2]);
        }
        G[i][i + 1][0] = F[i][i + 1];
    }
    for (int len = 3; len <= tmp.size(); len++) {
        for (int i = 0; i + len - 1 < tmp.size(); i++) {
            int j = i + len - 1;
            for (int k = 1; k <= n; k++) {
                if (tmp[i] == tmp[j]) {
                    G[i][j][k] = G[i + 1][j - 1][k - 2];
                }
                for (int p = i; p < j; p++) {
                    G[i][j][k] = max(G[i][j][k], G[i][p][k] + F[p + 1][j]);
                    G[i][j][k] = max(G[i][j][k], G[p + 1][j][k] + F[i][p]);
                }
                if (V[k] >= 0) F[i][j] = max(F[i][j], G[i][j][k] + V[k]);
            }
            G[i][j][0] = F[i][j];
        }
    }
    DP[0] = 0;
    for (int i = 1; i < n; i++) {
        DP[i] = DP[i - 1];
        for (int j = 1; j <= i; j++) {
            DP[i] = max(DP[i], DP[j - 1] + F[j][i]);
        }
    }
    cout << DP[n - 1] << endl;
    return 0;
}