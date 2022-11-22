#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

long long MAP[41];
int N;
long long M;
void dfs(int l, int r, long long sum, long long a[], long long &cnt) {
    if (sum > M) return;
    if (l > r) {
        a[++cnt] = sum;
        return;
    }
    dfs(l + 1, r, sum + MAP[l], a, cnt);
    dfs(l + 1, r, sum, a, cnt);
}

int main() {
    // Type your code here
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> MAP[i];
    }
    int mid = N / 2;
    long long ans = 0;
    long long suma[1 << 21], sumb[1 << 21], cnta, cntb;
    dfs(1, mid, 0, suma, cnta);
    dfs(mid + 1, N, 0, sumb, cntb);
    sort(suma + 1, suma + 1 + cnta);
    for (int i = 1; i <= cntb; i++) {
        ans += upper_bound(suma + 1, suma + 1 + cnta, M - sumb[i]) - suma - 1;
    }
    cout << ans << endl;
    return 0;
}