#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string add(string a, string b) {
    if (a == "0") return b;
    if (b == "0") return a;
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
            tt %= 10;
            xx.push_back('0' + tt);
        }
    }
    if (buffer != 0) {
        xx.push_back('0' + buffer);
    }
    reverse(xx.begin(), xx.end());
    return xx;
}

string multisingle(string a, int b) {
    if (a == "0" || b == 0) return "0";
    reverse(a.begin(), a.end());
    int buffer = 0;
    string xx;
    for (int i = 0; i < a.size(); i++) {
        int x = a[i] - '0';
        int tt = x * b + buffer;
        buffer = tt / 10;
        tt %= 10;
        xx.push_back('0' + tt);
    }
    if (buffer != 0) {
        xx.push_back('0' + buffer);
    }
    reverse(xx.begin(), xx.end());
    return xx;
}

string movemulti(string x, int i) {
    if (x[0] == '0') return "0";
    for (int m = i; m > 0; m--) {
        x += '0';
    }
    return x;
}

string multi(string a, string b) {
    string xx = "0";
    if (a.size() < b.size()) swap(a, b);
    reverse(b.begin(), b.end());
    for (int i = 0; i < b.size(); i++) {
        int y = b[i] - '0';
        xx = add(xx, movemulti(multisingle(a, y), i));
    }
    return xx;
}

int main() {
    // Type your code here
    string a, b;
    cin >> a >> b;
    cout << multi(a, b) << endl;
    return 0;
}