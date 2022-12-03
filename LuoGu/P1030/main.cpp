#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
string mi, ba;

void build(int ml, int mr, int bp, int br, int p) {
    if (ml > mr) return;
    if (ml == mr || bp == br) {
        cout << mi[ml];
        return;
    }
    int pos = 0;
    for (int i = ml; i <= mr; i++) {
        if (mi[i] == ba[br]) {
            pos = i;
        }
    }
    cout << mi[pos];
    if (pos >= 1) build(ml, pos - 1, bp, br - (mr - pos) - 1, p * 2);
    if (pos + 1 <= mi.size() - 1)
        build(pos + 1, mr, br - (mr - pos), br - 1, p * 2 + 1);
}

int main() {
    // Type your code here
    cin >> mi >> ba;
    build(0, mi.size() - 1, 0, ba.size() - 1, 1);
    cout << endl;
    return 0;
}