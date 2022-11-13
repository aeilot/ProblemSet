#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> pv;

int main() {
    // Type your code here
    int t;
    cin >> t;
    pv.resize(151);
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl
                 << "1 2" << endl;
        } else {
            int cnt = 0;
            int ans = ((n % 2 == 0) ? n / 2 : n / 2 + 1);
            cout << ans << endl;
            n *= 3;
            int j = n;
            for (int i = 1; i <= n; i += 3) {
                if (cnt >= ans) {
                    break;
                }
                cout << i << " " << j << endl;
                cnt++;
                j -= 3;
            }
        }
    }
    return 0;
}
