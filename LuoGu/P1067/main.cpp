#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--) {
        int a;
        cin >> a;
        if (a == 0) continue;
        if (i != n && a > 0) cout << "+";
        if (i > 1) {
            if (a != 1 && a != -1) cout << a << "x^" << i;
            else if (a == 1)
                cout << "x^" << i;
            else
                cout << "-x^" << i;
        } else if (i == 1) {
            if (a != 1 && a != -1) cout << a << "x";
            else if (a == 1)
                cout << "x";
            else
                cout << "-x";
        } else
            cout << a;
    }
    cout << endl;
    return 0;
}