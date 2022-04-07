#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n >= 20) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << pow(3, i) << " ";
            }
            cout << endl;
        }
    }
    return 0;
}