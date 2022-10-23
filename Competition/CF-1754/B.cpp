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
        if (n == 2)
            cout << "1 2" << endl;
        else if (n == 3)
            cout << "1 2 3" << endl;
        else if (n == 4)
            cout << "2 4 1 3" << endl;
        else {
            for (int j = 1; j <= n; j += 2) {
                cout << j << " ";
            }
            for (int j = 2; j <= n; j += 2) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    return 0;
}