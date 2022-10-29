#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string TWOS[81] = {"1",
                   "2",
                   "4",
                   "8",
                   "16",
                   "32",
                   "64",
                   "128",
                   "256",
                   "512",
                   "1024",
                   "2048",
                   "4096",
                   "8192",
                   "16384",
                   "32768",
                   "65536",
                   "131072",
                   "262144",
                   "524288",
                   "1048576",
                   "2097152",
                   "4194304",
                   "8388608",
                   "16777216",
                   "33554432",
                   "67108864",
                   "134217728",
                   "268435456",
                   "536870912",
                   "1073741824",
                   "2147483648",
                   "4294967296",
                   "8589934592",
                   "17179869184",
                   "34359738368",
                   "68719476736",
                   "137438953472",
                   "274877906944",
                   "549755813888",
                   "1099511627776",
                   "2199023255552",
                   "4398046511104",
                   "8796093022208",
                   "17592186044416",
                   "35184372088832",
                   "70368744177664",
                   "140737488355328",
                   "281474976710656",
                   "562949953421312",
                   "1125899906842624",
                   "2251799813685248",
                   "4503599627370496",
                   "9007199254740992",
                   "18014398509481984",
                   "36028797018963968",
                   "72057594037927936",
                   "144115188075855872",
                   "288230376151711744",
                   "576460752303423488",
                   "1152921504606846976",
                   "2305843009213693952",
                   "4611686018427387904",
                   "9223372036854775808",
                   "18446744073709551616",
                   "36893488147419103232",
                   "73786976294838206464",
                   "147573952589676412928",
                   "295147905179352825856",
                   "590295810358705651712",
                   "1180591620717411303424",
                   "2361183241434822606848",
                   "4722366482869645213696",
                   "9444732965739290427392",
                   "18889465931478580854784",
                   "37778931862957161709568",
                   "75557863725914323419136",
                   "151115727451828646838272",
                   "302231454903657293676544",
                   "604462909807314587353088"};

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

bool lesser(string a, string b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) return a[i] - '0' < b[i] - '0';
        }
        return false;
    }
    return a.size() < b.size();
}

string MAP[82][82];
string DP[82][82];

int main() {
    // Type your code here
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> MAP[i][j];
        }
    }
    string sum = "0";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            DP[j][j] = MAP[i][j];
        }
        for (int len = 2; len <= n; len++) {
            for (int j = 1; j + len - 1 < n; j++) {
                int z = j + len - 1;
                string one = "0", two = "0";
                if (z - 1 >= j)
                    one = add(DP[j][z - 1], multi(TWOS[j], MAP[i][z]));
                if (j + 1 <= z)
                    two = add(DP[j + 1][z], multi(TWOS[j], MAP[i][j]));
                DP[j][z] = (lesser(one, two)) ? two : one;
            }
        }
        sum = add(sum, DP[1][m]);
    }
    cout << sum << endl;
    return 0;
}