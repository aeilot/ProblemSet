#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int mmax = -100;
    int m;
    for (int i = 0; i < 7; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        int sum = t1 + t2;
        if (sum - 8 > mmax) {
            mmax = sum - 8;
            m = i + 1;
        }
    }
    if (mmax == 0)
        cout << 0 << endl;
    else
        cout << m << endl;
    return 0;
}