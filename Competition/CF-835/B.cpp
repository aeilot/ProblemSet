#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        int mmax = 0;
        for (int i = 0; i < a; i++) {
            char x;
            cin >> x;
            mmax = max(mmax, x - 'a' + 1);
        }
        cout << mmax << endl;
    }
    return 0;
}