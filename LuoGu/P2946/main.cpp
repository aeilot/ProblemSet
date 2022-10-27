#include <cstdio>
#include <iostream>

using namespace std;

#define MOD 100000000

int MAP[2010];
long long f[2010][2010];  // 按余数的背包

int main() {
    // Type your code here
    int N, F;
    cin >> N >> F;
    for (int i = 1; i <= N; i++) {
        cin >> MAP[i];
        MAP[i] %= F;
    }
    for (int i = 1; i <= N; i++) {
        f[i][MAP[i]] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < F; j++) {
            f[i][j] = (f[i][j] + f[i - 1][j] + f[i - 1][(j - MAP[i] + F) % F]) %
                      MOD;  // f[i][j] 考虑到了 只选这一个的情况
        }
    }
    cout << f[N][0] << endl;
    return 0;
}