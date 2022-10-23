#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Type your code here
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        stack<char> st;
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            if (x == 'Q') {
                st.push('Q');
            }
            if (x == 'A') {
                if (!st.empty()) st.pop();
            }
        }
        if (st.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}