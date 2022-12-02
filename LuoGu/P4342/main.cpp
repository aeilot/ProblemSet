#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

struct Edge {
    char op;
    int n;
} ED[150];

long long F[150][150], G[150][150];

int main() {
    // Type your code here
    int N;
    scanf("%d\n", &N);
    for (int i = 1; i <= 2 * N; i++) {
        for (int j = 1; j <= 2 * N; j++) {
            F[i][j] = -0x3f3f3f3f;
            G[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= N; i++) {
        char x;
        int n;
        scanf("%c %d", &x, &n);
        getchar();
        ED[i].n = n;
        ED[i].op = x;
        F[i][i] = ED[i].n;
        G[i][i] = ED[i].n;
    }
    for (int i = N + 1; i <= 2 * N; i++) {
        ED[i] = ED[i - N];
        F[i][i] = ED[i].n;
        G[i][i] = ED[i].n;
    }
    long long ans = -0x3f3f3f3f;
    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len - 1 <= 2 * N; i++) {
            int j = i + len - 1;
            for (int k = i; k + 1 <= j; k++) {
                char op = ED[k + 1].op;
                if (op == 't') {
                    F[i][j] = max(F[i][j], F[i][k] + F[k + 1][j]);
                    G[i][j] = min(G[i][j], G[i][k] + G[k + 1][j]);
                } else {
                    F[i][j] = max(F[i][j], F[i][k] * F[k + 1][j]);
                    F[i][j] = max(F[i][j], G[i][k] * G[k + 1][j]);
                    F[i][j] = max(F[i][j], F[i][k] * G[k + 1][j]);
                    F[i][j] = max(F[i][j], G[i][k] * F[k + 1][j]);
                    G[i][j] = min(G[i][j], G[i][k] * F[k + 1][j]);
                    G[i][j] = min(G[i][j], G[i][k] * G[k + 1][j]);
                    G[i][j] = min(G[i][j], F[i][k] * G[k + 1][j]);
                    G[i][j] = min(G[i][j], F[i][k] * F[k + 1][j]);
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        ans = max(ans, F[i][i + N - 1]);
    }
    cout << ans << endl;
    for (int i = 1; i <= N; i++) {
        if (F[i][i + N - 1] == ans) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}