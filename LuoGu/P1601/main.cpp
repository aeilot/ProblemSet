#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string add(string a, string b) {
    int buffer = 0;
    string xx;
    if (a.size() < b.size()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        int tt = x + y + buffer;
        buffer = tt / 10;
        tt = tt - buffer * 10;
        xx.push_back('0' + tt);
    }
    if (a.size() > b.size()) {
        for (int i = b.size(); i < a.size(); i++) {
            int x = a[i] - '0';
            int tt = x + buffer;
            buffer = tt / 10;
            tt = tt - buffer * 10;
            xx.push_back('0' + tt);
        }
    }
    if (buffer != 0) {
        xx.push_back('0' + buffer);
    }
    reverse(xx.begin(), xx.end());
    return xx;
}

int main() {
    // Type your code here
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    return 0;
}