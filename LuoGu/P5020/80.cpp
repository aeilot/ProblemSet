#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > CSys;

int dp[25001];
int w[101];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    CSys.resize(T);
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        CSys[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> CSys[i][j];
        }
        sort(CSys[i].begin(), CSys[i].end());
    }
    int wc = 0;
    for (int i = 0; i < T; i++) {
        memset(w, 0, sizeof(w));
        memset(dp, 0, sizeof(dp));
        if (wc == 0) w[wc++] = CSys[i][0];
        for (int j : CSys[i]) {
            for (int k = 0; k < wc; k++) {
                for (int x = w[k]; x <= j; x++) {
                    dp[x] = max(dp[x], dp[x - w[k]] + w[k]);
                }
            }
            if (dp[j] != j) w[wc++] = j;
        }
        cout << wc << endl;
        wc = 0;
    }
    return 0;
}
