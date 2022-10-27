#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int MAP[50000];
int vis[50000];

int main() {
    // Type your code here
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        memset(vis, 0, sizeof(vis));
        int n, ans = 0;
        cin >> n;
        int maxx = 0;
        for (int j = 1; j <= n; j++) {
            cin >> MAP[j];
            maxx = max(maxx, MAP[j]);
        }
        sort(MAP + 1, MAP + n + 1);
        for (int j = 1; j <= n; j++) {
            if (vis[MAP[j]]) continue;
            ans++;
            vis[MAP[j]] = 1;
            for (int k = MAP[j]; k <= maxx; k++) {
                if (vis[k - MAP[j]]) vis[k] = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}