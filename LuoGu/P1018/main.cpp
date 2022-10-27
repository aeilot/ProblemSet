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

bool lesser(string &p, string &q) {
    if (p.size() < q.size()) return true;
    if (p.size() > q.size()) return false;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] != q[i]) return p[i] < q[i];
    }
    return false;
}

string DP[46][46][16];
string num;

int main() {
    int N, K;
    cin >> N >> K;
    cin >> num;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            for (int k = 0; k <= K; k++) {
                DP[i][j][k] = "0";
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            DP[i][j][0] = num.substr(i, j - i + 1);
        }
    }
    for (int k = 1; k <= K; k++) {
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                for (int j = i + 1; j <= i + len - 1; j++) {
                    for (int m = 0; m < k; m++) {
                        string tmp = multi(DP[i][j - 1][m], DP[j][i + len - 1][k - m - 1]);
                        if (lesser(DP[i][i + len - 1][k], tmp)) DP[i][i + len - 1][k] = tmp;
                    }
                }
            }
        }
    }
    cout << DP[0][N - 1][K] << endl;
    return 0;
}
