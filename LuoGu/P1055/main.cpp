#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int code = 0;
    int step = 1;
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] == '-') continue;
        int bit = str[i] - '0';
        code += bit * (step++);
    }
    code = code % 11;
    int id;
    if (str[str.size() - 1] != 'X')
        id = str[str.size() - 1] - '0';
    else
        id = 10;
    if (code == id)
        cout << "Right" << endl;
    else {
        if (code != 10)
            cout << str.substr(0, str.size() - 1) << code << endl;
        else
            cout << str.substr(0, str.size() - 1) << "X" << endl;
    }
    return 0;
}