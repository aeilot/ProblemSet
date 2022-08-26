#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.size(); i++) {
        a[i] = toupper(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        b[i] = toupper(b[i]);
    }
    a = ' ' + a + ' ';
    b = ' ' + b + ' ';
    int ans = 0, count = 0;
    if (b.find(a) == string::npos) {
        cout << "-1" << endl;
    } else {
        int pos = b.find(a);
        ans = pos;
        count++;
        while (pos != string::npos) {
            pos = b.find(a, pos + 1);
            count++;
        }
        cout << count - 1 << ' ' << ans << endl;
    }
    return 0;
}