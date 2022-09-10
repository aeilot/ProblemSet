#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Type your code here
    stack<char> i;
    char c;
    while (cin >> c) {
        if (c == '@') break;
        if (c == '(')
            i.push(c);
        else if (c == ')') {
            if (i.empty()) {
                cout << "NO" << endl;
                return 0;
            };// 特殊情况要考虑
            i.pop();
        }
    }
    if (i.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}