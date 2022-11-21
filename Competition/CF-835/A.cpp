#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int t;
    cin >> t;
    while (t--) {
        int AR[3];
        cin >> AR[0] >> AR[1] >> AR[2];
        int mmax = 0, mmin = 200;
        for (int i = 0; i <= 2; i++) {
            mmin = min(AR[i], mmin);
            mmax = max(AR[i], mmax);
        }
        for (int i = 0; i <= 2; i++) {
            if (AR[i] != mmax && AR[i] != mmin) {
                cout << AR[i] << endl;
                break;
            }
        }
    }
    return 0;
}