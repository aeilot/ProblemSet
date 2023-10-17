#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

#define MOD 998244353

struct Node {
    int next, to;
} NDS[100010];

int cnt = 0;
int head[100010];

void add(int a, int b) {
    NDS[cnt].to = b;
    NDS[cnt].next = head[a];
    head[a] = cnt++;
}

vector<int> P;
int DP[2][100010];

map<int, int> Dict;

int main() {
    memset(head, -1, sizeof(head));
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int a, b;
        cin >> a >> b;
        int ida, idb;
        if (!(ida = Dict[a])) P.push_back(Dict[a] = ida = Dict.size());
        if (!(idb = Dict[b])) P.push_back(Dict[b] = idb = Dict.size());
        if (ida != idb) add(idb, ida);
    }
    if (!Dict[1]) P.push_back(Dict[1] = Dict.size());
    int Nc = Dict.size();
    int Fc = n - Nc, idf = Dict.size() + 1;
    int sum = 1, sum2 = 0;
    DP[0][Dict[1]] = 1;
    for (int i = 1; i <= m; i++) {
        int cur = i & 1;
        int prev = 1 - cur;
        sum2 = sum;
        sum = 0;
        for (int j : P) {
            DP[cur][j] = ((sum2 - DP[prev][j]) % MOD + MOD) % MOD;
            for (int x = head[j]; x != -1; x = NDS[x].next) {
                int y = NDS[x].to;
                if (y == j) continue;
                DP[cur][j] = ((DP[cur][j] - DP[prev][y]) % MOD + MOD) % MOD;
            }
            sum += DP[cur][j];
            sum %= MOD;
        }
        DP[cur][idf] =
            (1LL * sum2 * Fc % MOD - 1LL * DP[prev][idf] % MOD) % MOD;
        sum = (sum % MOD + DP[cur][idf] % MOD) % MOD;
    }
    cout << DP[m & 1][Dict[1]] % MOD << endl;
    return 0;
}
