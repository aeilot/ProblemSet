#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int a[110][110];
int f[20010];

int main() {
    // Type your code here
    int s, n, m;
    cin >> s >> n >> m;
    for (int i = 1; i <= s; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[j][i];// 翻转数组，方便排序
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(a[i] + 1, a[i] + 1 + s);// 方便计算，不需要 getV
    }
    for (int i = 1; i <= n; i++) {
        for (int mm = m; mm >= 0; mm--) {
            for (int j = 1; j <= s; j++) {
                if (mm - 2 * a[i][j] - 1 >= 0)
                    f[mm] = max(f[mm], f[mm - 2 * a[i][j] - 1] + i * j);
            }
        }
    }// 分组背包
    int ans = 0;
    for (int i = 0; i <= m; i++) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}