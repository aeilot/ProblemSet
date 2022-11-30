#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int AR[51];
int m, s;

int main() {
    // Type your code here
    int t;
    cin >> t;
    while (t--) {
        long long ra = 0, exp;
        int ma = 0;
        cin >> m >> s;
        for (int x = 1; x <= m; x++) {
            cin >> AR[x];
            ra += AR[x];
            ma = max(ma, AR[x]);
        }
        exp = ((ma + 1) * ma) / 2;
        if (s == exp - ra) {
            cout << "YES" << endl;
        } else {
            s -= (exp - ra);
            while (1) {
                ma++;
                s -= ma;
                if (s == 0) {
                    cout << "YES" << endl;
                    break;
                } else if (s < 0) {
                    cout << "NO" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}