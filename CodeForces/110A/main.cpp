#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // Type your code here
    string a;
    cin >> a;
    if (a == "0") {
        cout << "YES" << endl;
        return 0;
    }
    long long cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '7' || a[i] == '4') cnt++;
    }
    if (cnt == 0) {
        cout << "NO" << endl;
        return 0;
    }
    long long tmp = cnt;
    while (tmp > 0) {
        int t = tmp % 10;
        if (t != 4 && t != 7) {
            cout << "NO" << endl;
            return 0;
        }
        tmp /= 10;
    }
    cout << "YES" << endl;
    return 0;
}