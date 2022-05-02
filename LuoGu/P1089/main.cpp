#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    // Type your code here
    int c = 0;
    int deposit = 0;
    for (int i = 0; i < 12; i++) {
        int tmp;
        cin >> tmp;
        c += 300;
        if (c < tmp) {
            cout << "-" << i + 1 << endl;
            return 0;
        }
        c -= tmp;
        if (c >= 100) {
            deposit += 100 * (c / 100);
            c -= 100 * (c / 100);
        }
        // cout << c << "  " << deposit << endl;
    }
    c += double(deposit) * 1.2;
    cout << c << endl;
    return 0;
}