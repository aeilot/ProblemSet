#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

bool isAlpha(char a) { return a >= '0' && a <= '9'; }

bool isLetter(char a) { return a >= 'A' && a <= 'Z'; }

string AtoB(string &a) {
    int end = 0;
    int c = 0;
    for (int i = 0; i < a.size(); i++) {
        if (isAlpha(a[i])) {
            end = i - 1;
            break;
        } else {
            c++;
        }
    }
    c = 0;
    for (int i = end; i >= 0; i--) {
        c += (a[i] - 'A' + 1) * pow(26, end - i);
    }
    int r = atoi(a.substr(end + 1, a.size()).c_str());
    return "R" + to_string(r) + "C" + to_string(c);
}

string BtoA(string &a) {
    int enda = 0, stb = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 'C') {
            enda = i - 1;
            stb = i + 1;
        }
    }
    int r = atoi(a.substr(1, enda).c_str());
    int c = atoi(a.substr(stb, a.size()).c_str());
    string cs;
    int ct = 0;
    while (c > 0) {
        char a;
        if (c % 26 != 0)
            a = 'A' + c % 26 - 1;
        else
            a = 'Z';
        cs.push_back(a);
        c /= 26;
        ct++;
    }
    string cs2;
    for (int i = ct; i >= 0; i--) {
        cs2.push_back(cs[i]);
    }
    return cs2 + to_string(r);
}

int main() {
    int n = 0;
    cin >> n;
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp.at(0) != 'R')
            cout << AtoB(tmp);
        else {
            if (isLetter(tmp.at(1)))
                cout << AtoB(tmp);
            else {
                bool mark = false;
                for (int k = 2; k < tmp.size(); k++) {
                    if (tmp[k] == 'C') {
                        cout << BtoA(tmp);
                        mark = true;
                        break;
                    }
                }
                if (!mark) {
                    cout << AtoB(tmp);
                }
            }
        }
        cout << endl;
    }
    return 0;
}