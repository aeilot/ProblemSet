#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

struct pos {
    int up, down;
} POS[10010];
int n, m, k;
struct pipe {
    int low, high;
} PIP[10010];
bool vis[10010];
long long f[10010][1010];

int main() {
    // Type your code here
    long long ans = 0x3f3f3f3f;
    cin >> n >> m >> k;
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> POS[i].up >> POS[i].down;
    }
    for (int i = 0; i < k; i++) {
        int x = 0;
        cin >> x;
        cin >> PIP[x].low >> PIP[x].high;
        vis[x] = true;
    }
    for (int i = 0; i <= n; i++) {
        if (vis[i]) continue;
        PIP[i].low = 1;
        PIP[i].high = m;
    }
    // solve
    int cnt = 0, cp = 0;
    for (int j = 1; j <= m; j++) {
        f[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = POS[i].up+1; j <= POS[i].up+m; j++) {
            f[i][j] = min(f[i - 1][j - POS[i].up] + 1, f[i][j - POS[i].up] + 1);
        }
        for(int j = m+1; j<= m+POS[i].up; j++){
            f[i][m] = min(f[i][m], f[i][j]);
        }
        for(int j = 1; j<=m-POS[i].down; j++){
            f[i][j] = min(f[i-1][j + POS[i].down], f[i][j]);
        }
        for(int j=1; j<PIP[i].low; j++){
            f[i][j] = 0x3f3f3f3f;
        }
        for(int j=PIP[i].high+1; j<=m; j++){
            f[i][j] = 0x3f3f3f3f;
        }
        if(vis[i]){
            ans = 0x3f3f3f3f;
            for(int j = PIP[i].low+1; j<PIP[i].high; j++){
                ans = min(ans, f[i][j]);
            }
            if(ans >= 0x3f3f3f3f){
                cout << 0 << endl;
                cout << cnt << endl;
                return 0;
            }
            cnt++;
            cp = i;
        }
    }
    ans = 0x3f3f3f3f;
    for(int i = 1; i<=m; i++){
        ans = min(ans,f[n][i]);
    }
    cout << 1 << endl << ans << endl;
    return 0;
}