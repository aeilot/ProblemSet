#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int fa[30];

int main() {
    // Type your code here
    string s, t;
    cin >> s >> t;
    int Q;
    cin >> Q;
    string qry;
    string st1, st2;
    while (Q--) {
        st1.clear();
        st2.clear();
        cin >> qry;
        for (int i = 0; i < 30; i++) fa[i] = 0;
        for (int i = 0; i < qry.size(); i++) fa[qry[i] - 'a'] = 1;
        for (int i = 0; i < s.size(); i++) {
            if (fa[s[i] - 'a']) st1.push_back(s[i]);
        }
        for (int i = 0; i < t.size(); i++) {
            if (fa[t[i] - 'a']) st2.push_back(t[i]);
        }
        if (st1 == st2) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }
    cout << endl;
    return 0;
}