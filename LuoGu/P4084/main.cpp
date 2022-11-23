#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MOD 1000000007

struct Node {
    long long to, next;
} NDS[2000002];

long long head[1000002], vis[1000002];
long long cnt = 0;
long long F[1000002][4];

void add(long long u, long long v) {
    NDS[cnt].to = v;
    NDS[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(long long x) {
    vis[x] = 1;
    for (long long i = 1; i <= 3; i++) {
        if (F[x][i]) {
            for (long long j = 1; j < i; j++) F[x][j] = 0;
            break;
        }
        F[x][i] = 1;
    }
    for (long long i = head[x]; i != -1; i = NDS[i].next) {
        long long y = NDS[i].to;
        if (vis[y]) continue;
        dfs(y);
        F[x][1] = (F[x][1] * (F[y][2] + F[y][3] % MOD)) % MOD;
        F[x][2] = (F[x][2] * (F[y][1] + F[y][3] % MOD)) % MOD;
        F[x][3] = (F[x][3] * (F[y][2] + F[y][1] % MOD)) % MOD;
    }
}

int main() {
    // Type your code here
    memset(head, -1, sizeof(head));
    long long N, K;
    cin >> N >> K;
    for (long long i = 1; i <= N - 1; i++) {
        long long x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    for (long long i = 1; i <= K; i++) {
        int b, c;
        cin >> b >> c;
        F[b][c] = 1;
    }
    dfs(1);
    long long ans = (F[1][1] + F[1][2] + F[1][3]) % MOD;
    cout << ans << endl;
    return 0;
}