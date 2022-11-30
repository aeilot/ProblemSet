#include <cstdio>
#include <iostream>

using namespace std;

int MP[200010];

int main() {
    // Type your code here
    int t;
    cin >> t;
    while (t--) {
        int c;
        cin >> c;
        int mmax = 0, bmax = 0;
        int mmaid = 0;
        for (int i = 1; i <= c; i++) {
            cin >> MP[i];
            if (MP[i] >= mmax) {
                bmax = mmax;
                mmax = MP[i];
                mmaid = i;
            }
            if (MP[i] >= bmax && MP[i] <= mmax && mmaid != i) {
                bmax = MP[i];
            }
        }
        for (int i = 1; i <= c; i++) {
            if (MP[i] != mmax) {
                cout << MP[i] - mmax << " ";
            } else {
                cout << MP[i] - bmax << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
