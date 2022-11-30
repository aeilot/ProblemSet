#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

char getNext(char x) {
    if (x == 'Y') return 'e';
    if (x == 'e') return 's';
    return 'Y';
}

int main() {
    // Type your code here
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        // Solve
        char nxt;
        bool fg = false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != 'Y' && a[i] != 'e' && a[i] != 's') {
                cout << "NO" << endl;
                fg = true;
                break;
            }
            nxt = getNext(a[i]);
            if (i < a.size() - 1) {
                if (nxt != a[i + 1]) {
                    cout << "NO" << endl;
                    fg = true;
                    break;
                }
            }
        }
        if (fg == false) {
            cout << "YES" << endl;
        }
    }
    return 0;
}