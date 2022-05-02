#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int count(int n, int x) {
    int c = 0;
    string ns = to_string(n);
    char xs = to_string(x).c_str()[0];
    for (int i = 0; i < ns.length(); i++) {
        if (ns[i] == xs) c++;
    }
    return c;
}

int main() {
    // Type your code here
    int n, x;
    cin >> n >> x;
    if (n < x)
        cout << 0 << endl;
    else {
        int cc;
        for (int i = 1; i <= n; i++) {
            cc += count(i, x);
        }
        cout << cc << endl;
    }
    return 0;
}