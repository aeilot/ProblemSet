#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

int st[2000001];

int main() {
    // Type your code here
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        long long mmin = LLONG_MAX;
        long long ans = 0;
        for (int j = 0; j < N; j++) {
            long long tt;
            cin >> tt;
            ans += tt;
            mmin = min(mmin, tt);
        }
        ans -= 2 * mmin;
        cout << ans << endl;
    }
    return 0;
}