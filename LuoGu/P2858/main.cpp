#include <cstdio>
#include <iostream>

using namespace std;

int V[2010];
long long PRE[2010];
long long DP[2010][2010];

int main() {
    // Type your code here
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
        DP[i][i] = V[i];
        PRE[i] = PRE[i - 1] + V[i];
    }
    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len - 1 <= N; i++) {
            int j = i + len - 1;
            DP[i][j] = max(DP[i][j],
                           max(DP[i + 1][j] + PRE[j] - PRE[i] + V[i],
                               DP[i][j - 1] + PRE[j - 1] - PRE[i - 1] + V[j]));
        }
    }
    cout << DP[1][N] << endl;
    return 0;
}