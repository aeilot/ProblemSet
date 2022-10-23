#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        int ans = -1;
        for (int j = 0; j < n; j++) {
            int k;
            cin >> k;
            if (ans == -1)
                ans = k;
            else
                ans = ans ^ k;
        }
        cout << (ans == 0 ? "No" : "Yes") << endl;
    }
    return 0;
}