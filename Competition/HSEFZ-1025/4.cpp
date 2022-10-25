#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int n, m;
struct OP {
    char type;
    int num;
    OP(string &t, int num) {
        if (t == "XOR") type = 'x';
        else if (t == "AND")
            type = 'a';
        else
            type = 'o';
        this->num = num;
    }
    OP() {}

    int calc(int n) {
        if (type == 'x') return n ^ num;
        if (type == 'o') return n | num;
        if (type == 'a') return n & num;
        return 0;
    }
} ops[200001];

int chain(int num) {
    for (int i = 0; i < n; i++) {
        num = ops[i].calc(num);
    }
    return num;
}

int main() {
    // Type your code here
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        int num;
        cin >> tmp >> num;
        OP a = OP(tmp, num);
        ops[i] = a;
    }
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        int cc;
        switch (type) {
            case 1:
                cin >> cc;
                cout << chain(cc) << endl;
                break;
            case 2:
                string tmp;
                int num;
                cin >> cc >> tmp >> num;
                OP a = OP(tmp, num);
                ops[cc - 1] = a;
                break;
        }
    }
    return 0;
}