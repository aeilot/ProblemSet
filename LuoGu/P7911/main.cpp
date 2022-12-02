#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

map<string, long long> cb;
map<string, bool> sb;

bool check(string s) {
    long long a, b, c, d, port;
    if (sscanf(s.c_str(), "%lld.%lld.%lld.%lld:%lld", &a, &b, &c, &d, &port) !=
        5)
        return false;
    if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 ||
        d > 255 || port < 0 || port > 65535)
        return false;
    stringstream ss;
    ss << a << '.' << b << '.' << c << '.' << d << ':' << port;
    return ss.str() == s;
}

int main() {
    // Type your code here
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string op, ad;
        cin >> op >> ad;
        if (!check(ad)) {
            cout << "ERR" << endl;
            continue;
        }
        if (op == "Server") {
            if (!sb[ad]) {
                cout << "OK" << endl;
                cb[ad] = i + 1;
                sb[ad] = true;
            } else {
                cout << "FAIL" << endl;
            }
        } else {
            if (cb[ad] != 0) {
                cout << cb[ad] << endl;
            } else {
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}