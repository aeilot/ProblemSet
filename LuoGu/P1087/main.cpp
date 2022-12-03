#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

char TR[2000];
int PRE[2000];
int str[2000];
int N;
int mp = 0;

void build(int l, int r, int p) {
    mp = max(p, mp);
    int mid = (l + r) / 2;
    if (PRE[r] - PRE[l - 1] == r - l + 1) {
        TR[p] = 'I';
    } else if (PRE[r] - PRE[l - 1] == 0) {
        TR[p] = 'B';
    } else {
        TR[p] = 'F';
    }
    if (l == r) return;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);
}

void print(int p) {
    if (p > mp) return;
    print(p * 2);
    print(p * 2 + 1);
    cout << TR[p];
}

int main() {
    // Type your code here
    cin >> N;
    N = 1 << N;
    for (int i = 1; i <= N; i++) {
        char x;
        cin >> x;
        str[i] = x - '0';
        PRE[i] = PRE[i - 1] + str[i];
    }
    build(1, N, 1);
    print(1);
    cout << endl;
    return 0;
}