#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int vis[1010];
int primes[1010];
int cnt = 0;
long long mem[1010];

int main() {
    memset(vis, 0, sizeof(vis));
    memset(mem, 0, sizeof(mem));
    vis[1] = 1;
    for (int i = 1; i <= 1001; i++) {
        if (vis[i] == 0) {
            vis[i] = 1;
            primes[cnt++] = i;
        }
        for (int j = 0; j < cnt; j++) {
            if (i * primes[j] < 1010) vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
    int n;
    cin >> n;
    mem[0] = 1;
    for (int i = 0; i < cnt; i++) {
        if (primes[i] > n) break;
        for (int j = primes[i]; j <= n; j++) {
            mem[j] += mem[j - primes[i]];
        }
    }
    cout << mem[n] << endl;
    return 0;
}
